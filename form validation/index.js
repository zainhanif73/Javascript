function submitIt(){

    let user = document.getElementById("username").value;
    let email = document.getElementById("email").value;
    let address = document.getElementById("address").value;
    let phone = document.getElementById("phone").value;
    let msges = document.getElementById("msges").value;

    console.log(`Username: ${user}\nemail: ${email}\naddress: ${address}\nphone: ${phone}\nmsges: ${msges}`);

    let validuser = /^[a-zA-Z]{2,8}$/
    if (validuser.test(user) ){
        document.getElementById("username").classList.remove("is-invalid");
    }
    else{
        document.getElementById("username").classList.add("is-invalid");
    }

    let validphone = /^\+92[0-9]{10}$/

    if (validphone.test(phone)){
        document.getElementById("phone").classList.remove("is-invalid");
    }
    else{
        document.getElementById("phone").classList.add("is-invalid");
    }

    let validemail = /^[a-zA-Z.]{2,}@[a-zA-Z.]{5,}/
    if (validemail.test(email)){
        document.getElementById("email").classList.remove("is-invalid");
        console.log("Valid" + validemail)
    }
    else{
        document.getElementById("email").classList.add("is-invalid");
        console.log("InValid"+validemail)
    }

}