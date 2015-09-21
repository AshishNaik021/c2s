// validation on-key-press


function IsNumeric(e, obj) {
	var specialKeys = new Array();
    specialKeys.push(8); //Backspace
    var keyCode = e.which ? e.which : e.keyCode;
    var ret = ((keyCode >= 48 && keyCode <= 57) || specialKeys.indexOf(keyCode) != -1);
    obj.style.border = ret ? "none" : "2px solid #ff0000";
    return ret;
}


function onlyAlphabets(e, obj) {
		var specialKeys = new Array();
		specialKeys.push(8); //Backspace
		var keyCode = e.which ? e.which : e.keyCode;
		var ret = ((keyCode > 64 && keyCode < 91) || (keyCode > 96 && keyCode < 123) || specialKeys.indexOf(keyCode) != -1);
		obj.style.border = ret ? "none" : "2px solid #ff0000";
	    return ret;
}


function isAlphaNumeric(e, obj){
	var specialKeys = new Array();
	specialKeys.push(8); //Backspace
	var keyCode = e.which ? e.which : e.keyCode;
	var ret = ((keyCode > 47 && keyCode < 58) || (keyCode > 64 && keyCode < 91) || (keyCode > 96 && keyCode < 123) || specialKeys.indexOf(keyCode) != -1);
	obj.style.border = ret ? "none" : "2px solid #ff0000";
    return ret;
   
 } 