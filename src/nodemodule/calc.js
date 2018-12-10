exports.add = function(a,b) {
    return a + b;
}

function sub(a,b) {
    return a - b;
}
//  导出函数
exports.sub = sub;

class Calc {
    mul(a,b) {
        return a * b;
    }
}

//  导出类
exports.Calc = Calc;

//  导出对象
exports.calc = new Calc();

// 导出变量
module.exports.value = "hello world";
console.log(module)
//module.exports = {getName:function() {return "李宁"}}
exports ={getName:function() {return "李宁"}}
console.log(module)