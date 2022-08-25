// console.log("Hello Wrld");
// console.assert(4==4);
// document.write("This is document write");
//alert("me")


// var number1 = 32;
// var number2 = 32;
// console.log(number1+number2);


//Datatypes in javascript
// var str1 = "This is a string";
// var str2 = "This is also a string";
// var num = 2;
// console.log(number2*num);


//objects
// var marks = {
//     ravi: 34,
//     shuban: 78,
//     harry: 99.97
// }
// console.log(marks);


//undefine
// var c;
// console.log(c);


// var arr = [1,2,3,4,5];
// console.log(arr);


// let mydate = new Date();
// console.log(mydate.getHours()+" "+mydate.getMinutes()+" "+mydate.getSeconds());


// doc = document.getElementById("classme");
// doc[0].classList.add("bg-primary");
// doc[0].classList.add("bg-warning");


// document.getElementById("classme").style.border = "5px solid blue";

// let doc = document.getElementsByClassName("container");
// doc[0].style.background = "blue";
// doc[0].classList.add("bg-primary");

// btn = document.getElementsByTagName("div");


// createdElements = document.createElement('p');
// createdElements.innerText = "This is a created paragraph";
// btn[0].appendChild(createdElements);


// createdElements1 = document.createElement('p');
// createdElements1.innerText = "This is an another paragraph";
// btn[0].replaceChild(createdElements1 , createdElements);


// sel = document.querySelector(".container");
// console.log(sel);


//Events in javascript

// function clicked(){
//     console.log("Clicked");
// }
// window.onload = function(){
//     console.log("Page loaded");
// }

// classme.addEventListener('click' , function(){
//     console.log("Clicked");
// })

// classme.addEventListener('mouseover' , function(){
//     console.log("Mouse over classme");
// })

// classme.addEventListener('mouseout' , function(){
//     console.log("Mouse out classme");
// })

// let pre = document.querySelectorAll(".container")[1].innerHTML;
// classme.addEventListener('mouseup' , function(){
//     document.querySelectorAll(".container")[1].innerHTML = pre;
//     console.log("Mouse up when clicked");
// })

// classme.addEventListener('mousedown' , function(){
//     document.querySelectorAll(".container")[1].innerHTML = "<b> This is bold </b>";
//     console.log("Mouse down when clicked");
// })


//setTimeout and setInterval

// logkaro = ()=>{
//     console.log("I am your log");
// }
// // setTimeout(logkaro , 2000);

// clr = setInterval(logkaro , 1000);


// function call(){
//     let mydate = new Date()
//     let date = mydate.toLocaleDateString();
//     timer.innerText = date +" On "+ mydate.getHours()+":"+mydate.getMinutes()+":"+mydate.getSeconds();     
// }

// cls = setInterval(call , 1000)

// document.querySelector(".timer").innerText = 
// console.log(timer.innerText)

// var c = 1;
// let array=[];
// show();

//         function addData(){
//             let title = document.getElementById("title").value;
//             let des = document.getElementById("desc").value;
       
//             c+=1;
//             if (localStorage.getItem("item") != null){
//                 array = JSON.parse(localStorage.getItem("item"));    
//             }
//             array.push([title, des]);
//             localStorage.setItem("item" , JSON.stringify(array));
//             show();
//         }

//         function show(){  
//             let c1=1;
//             if (localStorage.getItem("item")!=null){
//                 document.querySelector(".itemadd").innerHTML= '';
//                 let array = JSON.parse(localStorage.getItem("item"));
//                 for (let i=0 ; i<array.length ; i++){
//                     item = document.createElement('tr');
//                     item.classList.add("row"+c1+"")
//                     item.innerHTML = "<th scope='row'>"+c1+"</th><td>"+array[i][0]+"</td><td>"+array[i][1]+"</td><td><button type='submit' class='btn btn-primary' onclick=deleted("+c1+")>Delete</button></td>";
//                     items = document.querySelector(".itemadd");
//                     items.appendChild(item);
//                     c1 = c1+1
//                 }
//             }
//             if (localStorage.getItem("item")==null || JSON.parse(localStorage.getItem("item")).length ==0){
//                 document.querySelector(".itemadd").innerHTML= 'Nothing To Show';
//             }
//         }
        
//         function deleted(del){
//             let array = JSON.parse(localStorage.getItem("item")); 
//             array.splice((del-1) , 1);
//             console.log(array);
//             localStorage.setItem("item" , JSON.stringify(array));
//             console.log(array.length);
//             show();
//         }


// function addData(){
    
//     const xhr = new XMLHttpRequest();
    
//     xhr.open('GET' , 'https://jsonplaceholder.typicode.com/posts' , true);
//     // xhr.getResponseHeader('Content-type' , 'application/json');
 
//     xhr.onprogress = function(){
//         console.log("On Progress")
//     }

//     xhr.onload = function(){
        
//         if (this.status == 200){
//             let x = JSON.parse(this.responseText);
//             for (let i=0 ; i<100 ; i++){
//                 console.log(x[i].title);
//             }
//         }        
//         else{
//             console.log("Some Error Occured");
//         }
//     }
   
//     xhr.send();
//     console.log("Done")
// }




// function addBook() {
//    let name = document.getElementById("name").value;
//    let author = document.getElementById("author").value;

//    let type; 

//    if (document.getElementById("flexRadioDefault1").checked){
//        type = "fiction";
//    }
//    else if (document.getElementById("flexRadioDefault2").checked){
//        type="Computer Programming";
//    }
//    else{
//         type="Cooking";
//    }
   
//    let array = [];
//    if (localStorage.getItem("item")!=null){
//         array = JSON.parse(localStorage.getItem("item"));
//    }
//    array.push([name , author, type]);
//    localStorage.setItem("item" , JSON.stringify(array));
//    show()
// }

// show()

// function show() {
//     let body = document.querySelector(".body");
//     let str = "";
//     let obj = localStorage.getItem("item");
//     if (obj != null){
//         JSON.parse(obj).forEach(element => {    
//         str+= `
//             <tr>
//             <th scope="col">${element[0]}</th>
//             <th scope="col">${element[1]}</th>
//             <th scope="col">${element[2]}</th>
//             </tr>` 
//         });
//     }
//     else{
//         str = "Nothing To Display";
//     }
//     body.innerHTML = str;

// }




function fetchBtn() {
    let url ="https://api.github.com/users"
    
    fetch(url).then((response)=>{
      return response.json()
    }).then((data)=>{
        data.forEach(element => {
            console.log(element.id);
        });
    })   
}

postbtn();
function postbtn() {
    url = "http://dummy.restapiexample.com/api/v1/create";
    data = `{"name":"test","salary":"123","age":"23"}`;
    params = {
        method : 'POST',
        headers : {
            'Content-Type' : 'application/x-www-form-urlencoded'
        },
        body : data
    }
    fetch(url , params).then(response=>{ 
        return response.json()
    }).then(data => console.log(data))
    
}