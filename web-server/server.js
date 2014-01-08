var fs = require('fs');
var url = require('url');
var path = require('path');
var static = require('lactate');

var docs_dir = process.env.STACKATO_DOCS_DIR || process.env.HOME;
var port = process.env.VCAP_APP_PORT || 8080;

var fileServer = static.dir(process.env.STACKATO_DOCS_DIR, {
    cache: 3600,
    autoindex: true
});

fileServer.notFound(function(request, response){
    serve404(request, response);
});

function serverError(request, response, err) {
    console.error(err);
    response.statusCode = 500;
    response.end('Internal server error (500)');
}

function serve404(request, response) {
    response.statusCode = 404;
    var stream = fs.createReadStream(path.join(__dirname, '404.html'));
    stream.pipe(response);
}

function serveFile(request, response) {
    var parsedUrl = url.parse(request.url);
    var indexFile = path.join(parsedUrl.pathname, 'index.html');
    fs.lstat(path.join(docs_dir, indexFile), function(err, stats) {
        if (!err) {
            fileServer.serve(indexFile, request, response);
        } else {
            fileServer.serve(request, response);
        }
    });
}

require('http').createServer(function (request, response) {
    request.addListener('end', function () {
        var parsedUrl = url.parse(request.url);
        if (parsedUrl.pathname.slice(-1) !== '/') {

            fs.lstat(path.join(docs_dir, parsedUrl.pathname), function(err, stats) {
                if (!err && stats.isDirectory()) {
                    response.statusCode = 302;
                    response.setHeader("Location", request.url + '/');
                    response.end();
                } else if (err && err.code == 'ENOENT') {
                    return serve404(request, response);
                } else {
                    return serveFile(request, response);
                }
            });
        }else{
            return serveFile(request, response);
        }
    });
    request.resume();
}).listen(port, function() {
    console.log("Docs server is listening on port: " + port);
});
