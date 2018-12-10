var add = require('./calc.js').add
console.log(add(20,40))

var {sub,Calc,calc,value} = require('./calc')

console.log(sub(30,40))
c = new Calc()
console.log(c.mul(30,40))
console.log(calc.mul(12,43))
console.log(value)