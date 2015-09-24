// JavaScript Document

function date_validatation(date_val, nameval, futDate){
	var myDate = date_val.split("/");

	if(date_val != ''){
		if(myDate[1] > 12){
			alert('Month Value Can Not be Greater Than 12!');
			document.getElementById(nameval).value = '';
		}else if(myDate[0] > 31 ){
			alert('Date Value Can Not be Greater Than 31!');
			document.getElementById(nameval).value = '';
		}
		else{
			if(futDate == 'future_date'){
				var currentDate = new Date();
				var day = currentDate.getDate();
				var month = currentDate.getMonth() + 1;
				var year = currentDate.getFullYear();
				var today = day + "/" + month + "/" + year;
				var myDate1 = new Date(myDate[2], myDate[1]-1, myDate[0]);
				
				if (myDate1 > currentDate) {
					alert("Future Date is Not Allowed!");
					document.getElementById(nameval).value = '';
				}
			}
		}
	}else{
			alert('Date is Empty! Please Enter Appropriate Value.');
	}	
}

function dob_and_age(date_val, nameval, futDate){
	var myDate = date_val.split("/");

	if(date_val != ''){
		if(myDate[1] > 12){
			alert('Month Value Can Not be Greater Than 12!');
			document.getElementById(nameval).value = '';
		}else if(myDate[0] > 31 ){
			alert('Date Value Can Not be Greater Than 31!');
			document.getElementById(nameval).value = '';
		}
		else{
			if(futDate == 'future_date'){
				var currentDate = new Date();
				var day = currentDate.getDate();
				var month = currentDate.getMonth() + 1;
				var year = currentDate.getFullYear();
				var today = day + "/" + month + "/" + year;
				var myDate1 = new Date(myDate[2], myDate[1]-1, myDate[0]);
				
				if (myDate1 > currentDate) {
					alert("Future Date is Not Allowed!");
					document.getElementById(nameval).value = '';
				}
			}
		}
	}else{
			alert('Date is Empty! Please Enter Appropriate Value.');
	}
	set_age(date_val);	
}

function date_range_validation(date_val, nameval, date1, date2){
	
	var myDate = date_val.split("/");
	var currentDate = new Date();
	var year = currentDate.getFullYear();
	var appDate = myDate[1]+"/"+myDate[0]+"/"+myDate[2];
	appDate = new Date(appDate);
	var Ndate1 = new Date(date1);
	var Ndate2 = new Date(date2);
	
	//alert('date1 = '+ date1 +' date2 =  '+ date2);

	if(date_val != ''){
		if(myDate[1] > 12){
			alert('Month Value Can Not be Greater Than 12!');
			document.getElementById(nameval).value = '';
		}else if(myDate[0] > 31 ){
			alert('Date Value Can Not be Greater Than 31!');
			document.getElementById(nameval).value = '';
		}
		else if((appDate<Ndate1) || (appDate>Ndate2) ) {
			alert('This Date Must Be Between '+ date1 +' and '+ date2);
			document.getElementById(nameval).value = '';
		}
	}
	else{
			alert('Date is Empty! Please Enter Appropriate Value.');
	}
	//set_age(date_val);	
}



function numeric_validation(myValue){
	newMyValue = myValue.replace(/[^0-9\.]/g, '');
	alert('myvalue = ' + newMyValue);
}

function isNumberKey(evt)
      {
         var charCode = (evt.which) ? evt.which : event.keyCode ;
         if((charCode >= 48 && charCode <= 57) || (charCode>187 && charCode<189)){
            return true;
		 }else{
         	return false;
		 }
      }

// ======================================================

function numbersonly(myfield, e, dec)
{
	var key;
	var keychar;
	
	if (window.event)
	   key = window.event.keyCode;
	else if (e)
	   key = e.which;
	else
	   return true;
	keychar = String.fromCharCode(key);
	
	// control keys
	if ((key==null) || (key==0) || (key==8) || 
		(key==9) || (key==13) || (key==27)  )
	   return true;
	
	// numbers
	else if ((("0123456789.").indexOf(keychar) > -1))
	   return true;
	
	// decimal point jump
	else if (dec && (keychar == "."))
	   {
	   myfield.form.elements[dec].focus();
	   return false;
	   }
	else
	   return false;
}

//===============================================================
function numericonly(myfield, e, dec)
{
	var key;
	var keychar;
	
	if (window.event)
	   key = window.event.keyCode;
	else if (e)
	   key = e.which;
	else
	   return true;
	keychar = String.fromCharCode(key);
	
	// control keys
	if ((key==null) || (key==0) || (key==8) || 
		(key==9) || (key==13) || (key==27)  )
	   return true;
	
	// numbers
	else if ((("0123456789").indexOf(keychar) > -1))
	   return true;
	
	// decimal point jump
	else if (dec && (keychar == "."))
	   {
	   myfield.form.elements[dec].focus();
	   return false;
	   }
	else
	   return false;
}
//===========================================================================

//===============================================================
function alphanumeric(myfield, e, dec)
{
	var key;
	var keychar;
        

        if (window.event)
	   key = window.event.keyCode;
	else if (e)
	   key = e.which;
	else
	   return true;
	keychar = String.fromCharCode(key);
	
	// control keys
	if ((key==null) || (key==0) || (key==8) || 
		(key==9) || (key==13) || (key==27)  )
	   return true;
	
	// numbers
	else if ((("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ. ").indexOf(keychar) > -1))
	   return true;
	
	// decimal point jump
	else if (dec && (keychar == "."))
	   {
	   myfield.form.elements[dec].focus();
	   return false;
	   }
	else
	   return false;
}

//===========================================================================

function esic_pf(myfield, e, dec)
{
	var key;
	var keychar;

        if (window.event)
	   key = window.event.keyCode;
	else if (e)
	   key = e.which;
	else
	   return true;
	keychar = String.fromCharCode(key);
	
	// control keys
	if ((key==null) || (key==0) || (key==8) || 
		(key==9) || (key==13) || (key==27)  )
	   return true;
	
	// numbers
	else if ((("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ").indexOf(keychar) > -1))
	   return true;
	
	// decimal point jump
	else if (dec && (keychar == "."))
	   {
	   myfield.form.elements[dec].focus();
	   return false;
	   }
	else
	   return false;
}

//===========================================================================

function pan_(myfield, e, dec)
{
	var key;
	var keychar;

        if (window.event)
	   key = window.event.keyCode;
	else if (e)
	   key = e.which;
	else
	   return true;
	keychar = String.fromCharCode(key);
	
	// control keys
	if ((key==null) || (key==0) || (key==8) || 
		(key==9) || (key==13) || (key==27)  )
	   return true;
	
	// numbers
	else if ((("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ").indexOf(keychar) > -1))
	   return true;
	
	// decimal point jump
	else if (dec && (keychar == "."))
	   {
	   myfield.form.elements[dec].focus();
	   return false;
	   }
	else
	   return false;
}
// ==============================================================================================



function mobile_phone(myfield, e, dec)
{
	var key;
	var keychar;
	
	if (window.event)
	   key = window.event.keyCode;
	else if (e)
	   key = e.which;
	else
	   return true;
	keychar = String.fromCharCode(key);
	
	// control keys
	if ((key==null) || (key==0) || (key==8) || 
		(key==9) || (key==13) || (key==27)  )
	   return true;
	
	// numbers
	else if ((("0123456789+-").indexOf(keychar) > -1))
	   return true;
	
	// decimal point jump
	else if (dec && (keychar == "."))
	   {
	   myfield.form.elements[dec].focus();
	   return false;
	   }
	else
	   return false;
}


function format(input)
{    
    var nStr =  input.value + '';
    nStr = nStr.replace( /\,/g, "");
    var x = nStr.split( '.' );
    var x1 = x[0];
    var x2 = x.length > 1 ? '.' + x[1] : '';
    var rgx = /(\d+)(\d{3})/;
    if ( rgx.test(x1) ) {
        x1 = x1.replace( rgx, '$1' + ',' + '$2' );
    }
    var y = x1.split( ',' );
    var x3 = y[0];
     rgx = /(\d+)(\d{2})/;
        while ( rgx.test(x3) ) {
            x3 = x3.replace( rgx, '$1' + ',' + '$2' );            
        }
    input.value = (y[1]) ? x3 + ',' + y[1] + x2 : x1 + x2;
}


function textonly(inputtxt, id)
  {	  
   var letters = /^[A-Za-z]+\s\d$/;
   if(inputtxt.value.match(letters))
     {
      return true;
     }
   else
     {
     alert("Only Alphabetic Characters & '.' are allowed!");
	 document.getElementById(id).value = '';
	 document.getElementById(id).focus();
     return false;
     }
  }
  

function charonly(myfield, e)
{   
	var key;
	var keychar;
	
	if (window.event)
	   key = window.event.keyCode;
	else if (e)
	   key = e.which;
	else
	   return true;
	keychar = String.fromCharCode(key);
	
	// control keys
	if ((key==null) || (key==0) || (key==8) || 
		(key==9) || (key==13) || (key==27)  )
	   return true;
	
	// numbers
	else if ((("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ. ").indexOf(keychar) > -1))
	   return true;
	else
		return false;
	
}



function charonlyexdot(myfield, e)
{
	var key;
	var keychar;
	
	if (window.event)
	   key = window.event.keyCode;
	else if (e)
	   key = e.which;
	else
	   return true;
	keychar = String.fromCharCode(key);
	
	// control keys
	if ((key==null) || (key==0) || (key==8) || 
		(key==9) || (key==13) || (key==27)  )
	   return true;
	
	// numbers
	else if ((("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ").indexOf(keychar) > -1))
	   return true;
	else
		return false;
	
}

function validateEmail(email)
{
    debugger;
    var reg = /^\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$/;
    if (reg.test(email)){
         
    }else{
        alert("Invalid email"); 
    }
}  

function mailid(myfield, e)
{
	var key;
	var keychar;
	
	if (window.event)
	   key = window.event.keyCode;
	else if (e)
	   key = e.which;
	else
	   return true;
	keychar = String.fromCharCode(key);
	
	// control keys
	if ((key==null) || (key==0) || (key==8) || 
		(key==9) || (key==13) || (key==27)  )
	   return true;
	
	// numbers
	else if ((("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.@_0123456789").indexOf(keychar) > -1))
	   return true;
	else
		return false;
	
}


function idfields(myfield, e)
{
	var key;
	var keychar;
	
	if (window.event)
	   key = window.event.keyCode;
	else if (e)
	   key = e.which;
	else
	   return true;
	keychar = String.fromCharCode(key);
	
	// control keys
	if ((key==null) || (key==0) || (key==8) || 
		(key==9) || (key==13) || (key==27)  )
	   return true;
	
	// numbers
	else if ((("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-").indexOf(keychar) > -1))
	   return true;
	else
		return false;
	
}



function to_date_validate(date_val){
	
	var to_date = date_val.split("/");
	
	var fdate = document.getElementById('edit-from-date-datepicker-popup-0').value;
	var from_date = fdate.split("/");
	
	if(fdate != ''){
		if(to_date[2] < from_date[2]){
			alert('"To Date" Can Not be Less Than "From Date"!');
			document.getElementById('edit-to-date-datepicker-popup-0').value = '';
		}else if( (to_date[2]<=from_date[2]) && (to_date[1]<from_date[1]) ){
			alert('"To Date" Can Not be Less Than "From Date"!');
			document.getElementById('edit-to-date-datepicker-popup-0').value = '';
		}else if( (to_date[2]<=from_date[2]) && (to_date[1]<=from_date[1]) && (to_date[0]<from_date[0])){
			alert('"To Date" Can Not be Less Than "From Date"!');
			document.getElementById('edit-to-date-datepicker-popup-0').value = '';
		}else{
			//alert('all is well!');
		}
	}else{
			alert('From Date is Empty! Please Enter Appropriate Value.');
	}
}


function coff_date_validate(date_val){
	var to_date = date_val.split("/");
	var fdate = document.getElementById('edit-from-date-datepicker-popup-0').value;
	var from_date = fdate.split("/");
	
	if(fdate != ''){
		if(to_date[2] < from_date[2]){
			alert('"Compensatory Off Date" Can Not be Earlier Than "Work Date"!');
			document.getElementById('edit-to-date-datepicker-popup-0').value = '';
			
		}else if( (to_date[2]<=from_date[2]) && (to_date[1]<from_date[1]) ){
			alert('"Compensatory Off Date" Can Not be Earlier Than "Work Date"!');
			document.getElementById('edit-to-date-datepicker-popup-0').value = '';
		}else if( (to_date[2]<=from_date[2]) && (to_date[1]<=from_date[1]) && (to_date[0]<from_date[0])){
			alert('"Compensatory Off Date" Can Not be Earlier Than "Work Date"!');
			document.getElementById('edit-to-date-datepicker-popup-0').value = '';
		}else{
			//alert('all is well!');
		}
	}else{
			alert('From Date is Empty! Please Enter Appropriate Value.');
	}
}

function date_range_validatation(date_val, nameval, date1, date2){
	
	//alert('Date '+date1+'Date '+date2);
	//alert('Date '+date_val);
	var myDate = date_val.split("/");
	//var year = currentDate.getFullYear();
	//alert('Date '+year);
	var currentDate = new Date();
	var year = currentDate.getFullYear();

	if(date_val != ''){
		if(myDate[1] > 12){
			alert('Month Value Can Not be Greater Than 12!');
			document.getElementById(nameval).value = '';
		}else if(myDate[0] > 31 ){
			alert('Date Value Can Not be Greater Than 31!');
			document.getElementById(nameval).value = '';
		}
		else if(myDate[2] < year-1 || myDate[2] > year){
			alert('Medical Bill should be claim in this year  '+year);
			document.getElementById(nameval).value = '';

		}
		
	}
	else{
			alert('Date is Empty! Please Enter Appropriate Value.');
	}
	//set_age(date_val);	
}

