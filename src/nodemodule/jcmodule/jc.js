function jc(n) {
    if(n < 1) {
        return 1;
    } else {
        return n * jc(n-1);
    }
}
function add(a,b,c) {
    return a + b + c;
}
exports.jc = jc;
exports.add = add;