// validation on-key-press


function IsNumeric(e, obj) {
	var specialKeys = new Array();
    specialKeys.push(8); //Backspace
    var keyCode = e.which ? e.which : e.keyCode;
    var ret = ((keyCode >= 48 && keyCode <= 57) || specialKeys.indexOf(keyCode) != -1);
    obj.style.border = ret ? "1px solid #d4d4d4" : "2px solid #ff0000";
    return ret;
}


function onlyAlphabets(e, obj) {
		var specialKeys = new Array();
		specialKeys.push(8); //Backspace
		
		var keyCode = e.which ? e.which : e.keyCode;
		var ret = ((keyCode > 64 && keyCode < 91) || (keyCode > 96 && keyCode < 123) || specialKeys.indexOf(keyCode) != -1);
		obj.style.border = ret ? "1px solid #d4d4d4" : "2px solid #ff0000";
	    return ret;
}


function isAlphaNumeric(e, obj){
	var specialKeys = new Array();
	specialKeys.push(8); //Backspace
	specialKeys.push(32); //Space
	var keyCode = e.which ? e.which : e.keyCode;
	var ret = ((keyCode > 47 && keyCode < 58) || (keyCode > 64 && keyCode < 91) || (keyCode > 96 && keyCode < 123) || specialKeys.indexOf(keyCode) != -1);
	obj.style.border = ret ? "1px solid #d4d4d4" : "2px solid #ff0000";
    return ret;
   
 } 

function MailId(e, obj)
{
	var specialKeys = new Array();
	specialKeys.push(8); //Backspace
	specialKeys.push(32); //Space
	specialKeys.push(64); //@
	specialKeys.push(95); //Underscore
	
	var keyCode = e.which ? e.which : e.keyCode;
	var ret = ((keyCode > 47 && keyCode < 58) || (keyCode > 64 && keyCode < 91) || (keyCode > 96 && keyCode < 123) || specialKeys.indexOf(keyCode) != -1);
	obj.style.border = ret ? "none" : "2px solid #ff0000";
    return ret;
	
}