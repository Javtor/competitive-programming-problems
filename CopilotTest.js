// Express server on port 3000
var express = require('express');
var app = express();
var server = require('http').createServer(app);
var io = require('socket.io').listen(server);
var port = process.env.PORT || 3000;

// Serve static files from the public directory
app.use(express.static(__dirname + '/public'));

// When a user connects
io.sockets.on('connection', function (socket) {
    console.log('User connected');
    socket.emit('message', {
        message: 'Welcome to CopilotTest.js'
    });

    // When a user disconnects
    socket.on('disconnect', function () {
        console.log('User disconnected');
    });

    // When a user sends a message
    socket.on('message', function (data) {
        console.log('Message: ' + data.message);
        socket.broadcast.emit('message', data);
    });
});

// Start the server
server.listen(port, function () {
    console.log('Server listening at port %d', port);
});