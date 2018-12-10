/*

module对象

exports

module.exports和exports的区别

如果只向exports对象添加属性，是一样的，但是可以替换module.exports对象，如module.exports = {}
exports = {}

 */

var getName = require('./calc.js').getName
var add = require('./calc.js').add
console.log(getName())
console.log(add(1,2))