#!/usr/bin/env node

var NODES = [
  '192.168.2.141',
  '192.168.2.157',
  '192.168.2.89',
  '192.168.2.44',
  '192.168.2.179',
  '192.168.2.156'
]

var SSH = require('simple-ssh');

NODES.forEach(function(n){
  console.log('--- connecting to', n);
  
  var ssh = new SSH({
    host: n,
    user: 'root',
    pass: 'arduino'
  });

  ssh.exec('reset-mcu', {
    out: function(stdout) {
      console.log(n, ':', stdout);
    }
  }).start();
});
