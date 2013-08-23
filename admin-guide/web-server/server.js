var fs = require('fs');
var url = require('url');
var path = require('path');
var static = require('node-static');

var fileServer = new static.Server(process.env.HOME, { cache: 3600 });

function serveFile(request, response){
    fileServer.serve(request, response, function(e, res){
            if (e && (e.status === 404)) {
                fileServer.serveFile('/404.html', 404, {}, request, response);
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
                }else{
                    return serveFile(request, response);
                }
            });
        }else{
          return serveFile(request, response);
        }
    });
}).listen(process.env.VCAP_APP_PORT || 8080);
