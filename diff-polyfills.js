//Bind polyfill
//Polyfill for bind--------------------------------------------------------1
Function.prototype.myBind = function () {
    if (typeof arguments[0] === 'function') {
      throw new Error('Function not allowed');
    }
    var Object = arguments[0];
    var vars = [];
    var context = this;
    for (var i = 1; i < arguments.length; i++) {
      vars.push(arguments[i]);
    }
    return function () {
      return context.call(Object, vars);
    };
  };
  var object = {
    name: 'manish',
    age: 35,
  };
  
  function display(someThing) {
    console.log(
      `my nam is ${this.name} and my age is ${this.age} i like ${someThing}`
    );
  }
  
  let result = display.myBind(object, 'movies');
  result();
  
  //polyfill for higher order function------------------------------------------2
  
  //polyfill for map------------------------------------------------------------2.1
  Array.prototype.myMap = function (callBack) {
    var results = [];
    for (var i = 0; i < this.length; i++) {
      results.push(callBack(this[i], i, this));
    }
    return results;
  };
  
  let arr = [2, 4, 6, 8, 10, 12, 14];
  
  let arr1 = arr.myMap((item) => {
    return item + 1;
  });
  console.log('result', arr1);
  
  //polyfill for filter-----------------------------------------------------------2.2
  Array.prototype.myFilter = function (callBack) {
    var results = [];
  
    for (var i = 0; i < this.length; i++) {
      if (callBack.call(null, this[i], i, this)) {
        results.push(this[i]);
      }
    }
    return results;
  };
  
  let arrF = [2, 43, 63, 81, 11, 12, 14];
  
  let arrF1 = arrF.myFilter((item) => {
    return item % 2 === 0;
  });
  console.log('result', arrF1);
  
  
  