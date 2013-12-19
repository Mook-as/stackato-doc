var fs = require('fs');
var url = require('url');
var path = require('path');
var static = require('node-static');

var fileServer = new static.Server(process.env.HOME, { cache: 3600 });
var port = process.env.VCAP_APP_PORT || 8080;

function serverError(request, response, err) {
    console.error(err);
    response.statusCode = 500;
    response.end('Internal server error (500)');
}

function serve404(request, response) {
    fileServer.serveFile('/404.html', 404, {}, request, response);
}

function serveFile(request, response) {
    fileServer.serve(request, response, function(e, res) {
        if (e && (e.status === 404)) {
            return serve404(request, res);
        } else if (e) {
            return serverError(request, response, e);
        }
    });
}

require('http').createServer(function (request, response) {
    request.addListener('end', function () {
        var parsedUrl = url.parse(request.url);
        if (parsedUrl.pathname.slice(-1) !== '/') {

            fs.lstat(path.join(process.env.HOME, parsedUrl.pathname), function(err, stats) {
                if (!err && stats.isDirectory()) {
                    response.statusCode = 302;
                    response.setHeader("Location", request.url + '/');
                    response.end();
                } else if (err && err.code == 'ENOENT') {
                    return serve404(request, response, err);
                } else {
                    return serveFile(request, response);
                }
            });
        }else{
            return serveFile(request, response, err);
        }
    });
    request.resume();
}).listen(port, function() {
    console.log("Docs server is listening on port: " + port);
});
