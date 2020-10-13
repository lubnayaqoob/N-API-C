//The string passed to require() is the name of the target in binding.gyp responsible for creating the .node file.
const addon = require('./build/Release/module');
addon.helloWorld();