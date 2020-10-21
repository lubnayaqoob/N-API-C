const addon = require('./build/Release/module');
const can_id = 2;    
const res = addon.helloWorld(can_id);
console.log("addon.helloWorld(can_id)-------", res );
