// validation on-key-press


function IsNumeric(e, obj) {
	var specialKeys = new Array();
    specialKeys.push(8); //Backspace
    var keyCode = e.which ? e.which : e.keyCode;
    var ret = ((keyCode >= 48 && keyCode <= 57) || specialKeys.indexOf(keyCode) != -1);
    obj.style.border = ret ? "1px solid #d4d4d4" : "2px solid #ff0000";
    obj.style.background = ret ? "#ffffff" : "#ffefef";
    return ret;
}

function phoneNumber(e, obj) {
	var specialKeys = new Array();
    specialKeys.push(8);  //Backspace
    specialKeys.push(46); //Delete
    specialKeys.push(45); //Dash '-'
    var keyCode = e.which ? e.which : e.keyCode;
    var ret = ((keyCode >= 48 && keyCode <= 57) || specialKeys.indexOf(keyCode) != -1);
    obj.style.border = ret ? "1px solid #d4d4d4" : "2px solid #ff0000";
    obj.style.background = ret ? "#ffffff" : "#ffefef";
    return ret;
}

function onlyAlphabets(e, obj) {
		var specialKeys = new Array();
		specialKeys.push(8); //Backspace
		
		var keyCode = e.which ? e.which : e.keyCode;
		var ret = ((keyCode > 64 && keyCode < 91) || (keyCode > 96 && keyCode < 123) || specialKeys.indexOf(keyCode) != -1);
		obj.style.border = ret ? "1px solid #d4d4d4" : "2px solid #ff0000";
		obj.style.background = ret ? "#ffffff" : "#ffefef";
	    return ret;
}


function isAlphaNumeric(e, obj){
	var specialKeys = new Array();
	specialKeys.push(8); //Backspace
	specialKeys.push(32); //Space
	var keyCode = e.which ? e.which : e.keyCode;
	var ret = ((keyCode > 47 && keyCode < 58) || (keyCode > 64 && keyCode < 91) || (keyCode > 95 && keyCode < 123) || specialKeys.indexOf(keyCode) != -1);
	obj.style.border = ret ? "1px solid #d4d4d4" : "2px solid #ff0000";
    obj.style.background = ret ? "#ffffff" : "#ffefef";
    return ret;
   
 } 

function isMailId(e, obj)
{
	var specialKeys = new Array();
	specialKeys.push(8);   //Backspace
	specialKeys.push(46);  //Delete
	specialKeys.push(64);  //@
	specialKeys.push(95);  //Underscore '_'
	specialKeys.push(190); //Dot / Period '.'
	
	var keyCode = e.which ? e.which : e.keyCode;
	var ret = ((keyCode > 47 && keyCode < 58) || (keyCode > 64 && keyCode < 91) || (keyCode > 95 && keyCode < 123) || specialKeys.indexOf(keyCode) != -1);
	obj.style.border = ret ? "1px solid #d4d4d4" : "2px solid #ff0000";
    obj.style.background = ret ? "#ffffff" : "#ffefef";
    return ret;
	
}

function ValidateForm(){
alert($("#edit-agent-relationship").value()	);
return false;
}