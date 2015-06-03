#!/usr/bin/env node

var NODES = [
  'yun1.local', // light-emitter - 192.168.2.141
  'yun12.local', // motion-emitter - 192.168.2.157
  'yun10.local', // force-detector - 192.168.2.89
  'yun2.local', // force-emitter - 192.168.2.44
  'yun3.local', // motion-detector - 192.168.2.179
  'yun5.local' // light-detector - 192.168.2.156
]

var SSH = require('simple-ssh');

NODES.forEach(function(n){
  console.log('--- connecting to', n);
  
  var ssh = new SSH({
    host: n,
    user: 'root',
    pass: 'arduino',
    timeout: 30 * 1000
  });

  ssh.exec('reset-mcu', {
    out: function(stdout) {
      console.log(n, '- out:', stdout);
    },
    err: function(stderr) {
      console.log(n, '- err:', stderr);
    },
    exit: function(code) {
      console.log(n, '- exit with:', code);
    }
  }).start({
    success: function() {
      console.log(n, '- connected:', n);
    },
    fail: function() {
      console.log(n, '- failed:', n);
    }
  });
});
