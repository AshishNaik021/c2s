jq(document).ready(function(){
	jq('#ot-hours-wrap select').each(function(){
		jq(this).change(function(){
		
			var st = jq('#edit-ot-start-time').val();
			var sa = jq('#edit-ot-start-time-ampm').val();
			var et = jq('#edit-ot-end-time').val();
			var ea = jq('#edit-ot-end-time-ampm').val();

			var h1 		= st.toString().split(".")[0];
			var m1  	= st.toString().split(".")[1];
			
			var h2 		= et.toString().split(".")[0];
			var m2  	= et.toString().split(".")[1];
			
			var add_min	= 60;



			//Math.abs(-7.25);

			var h1 = parseFloat(h1);
			var h2 = parseFloat(h2);

			if(sa == 'PM'){	if(h1 < 12){var h1 = h1+12; } }
			if(ea == 'PM'){	if(h2 < 12){var h2 = h2+12; } }
			
			if(sa == 'AM'){	if(h1 >= 12){var h1 = 0; var add_min = 0; } }
			if(ea == 'AM'){	if(h2 >= 12){var h2 = 0; var add_min = 0; } }
			
			if(sa == ea ){if(h2 < h1 ){ hrs = 24-hrs;  } }
			
			var hrs = Math.abs(h2 - h1);
			
			if(m1 == 00 ){
				m1 = parseFloat(m1)+ add_min;
			}
			if( m2 == 00){
				m2 = parseFloat(m2)+add_min;
			}
			var minute = Math.abs(m2-m1);

			jq('#edit-ot-hours').val(hrs+'.'+minute);

			if(st == et){
				if(sa == ea){
					jq('#edit-ot-hours').val(24);
				}
			}
			if(st==0 || et==0){
					jq('#edit-ot-hours').val('');
			}
		});	
	});
	
	var othrs  = 0;	hours = 0; minute = 0; quo = 0; rem = 0; total_hours =0; total_minutes = 0; var totalothrs = 0;
	jq('.ot-hours input').each(function(){
		hours1 = 0;
		valx = jq(this).val();
		valx_temp = valx.split(".");
		hours = parseInt(hours) + parseInt(valx_temp[0]); 
		minute = parseInt(minute) + parseInt(valx_temp[1]); 
	});
	quo += minute/60 ; 
	rem += minute%60 ;
	
	total_hours = parseInt(hours) + parseInt(quo); 
	total_minutes = rem; 
	jq('#edit-total-ot-hours').val(total_hours+"."+total_minutes);

	jq('.approved-ot-hours input').each(function(){
		jq(this).attr('maxlength','5');
	});
	
	jq('.approved-ot-hours input').change(function(){
		
		var total_hours = 0; var tot_hours = 0; var tot_min = 0; var rem = 0; var quo = 0; var hours = 0; minute = 0; var valx = 0; var incr =0;
			var applied_ot_hours  = 0; var alert_flag = 0;
			jq('.approved-ot-hours input').each(function(){
				applied_ot_hours = jq('#appl_hours_'+incr).text();
				var valx = jq(this).val();
				if(valx.indexOf(".")==0){
					//valx = 0+valx;
					valx = applied_ot_hours;
				}
				if(valx == 0){valx = '0.0'; }
				if(valx > 0){valx = valx+'.0'; }
				if(valx == '.'){valx = 0; alert('Invalid Time Enter');  }
				if( (parseFloat(valx)>parseFloat(applied_ot_hours)) && (alert_flag == 0) ){
						alert('You can not increase the OT Hours.'); 
						jq('#edit-approved-ot-hours'+incr).val(applied_ot_hours) ;
						alert_flag = 1;
						valx = applied_ot_hours;
				}
				if( (parseFloat(valx)==0.30) && (alert_flag == 0) ){
						alert('Minimum one hour is Required to  approve O.T.'); 
						jq('#edit-approved-ot-hours'+incr).val(applied_ot_hours) ;
						alert_flag = 1;
						valx = applied_ot_hours;
				}
				if( (parseFloat(valx) == '') ){
						jq('#edit-approved-ot-hours'+incr).val(0) ;
				}
				valx_temp = valx.split(".");
				
				if(parseInt(valx_temp[1]) <= 59 && parseInt(valx_temp[1]) != 0){
					//alert('OT Hours Should be Multiple of 30 Minutes only.'); 
					valx_temp[1] = 30;
					var hrs = valx_temp[0]+'.'+valx_temp[1];
					if(hrs==0.30){
						jq('#edit-approved-ot-hours'+incr).val(applied_ot_hours);
					}else{
						jq('#edit-approved-ot-hours'+incr).val(hrs);
					}
				}else{
					valx_temp[1] = '00';
					var hrs = valx_temp[0]+'.'+valx_temp[1]
					if(hrs==0.30){
						jq('#edit-approved-ot-hours'+incr).val(applied_ot_hours);
					}else{
						jq('#edit-approved-ot-hours'+incr).val(hrs);
					}
				}

				hours = parseInt(hours) + parseInt(valx_temp[0]); 
				minute = parseInt(minute) + parseInt(valx_temp[1]);
				
				
				incr++;
			});
			
			quo += minute/60 ; 
			rem += minute%60 ;
			tot_hours  = parseInt(hours) + parseInt(quo);
			tot_min    = parseFloat(rem/100);
			total_hours = tot_hours + tot_min;
			
			if(isNaN(total_hours)) {
				alert('Invalid Number are Chosen');
			}
			jq('#edit-total-approved-ot-hours').val(total_hours.toFixed(2));
	});
});




function decimal_numberformat(input)
{
	var afterDecimal = '0';  beforeDecimal = '0'; 
	if(input.value.indexOf(".")==0){
		input.value = 0+input.value;
	}
	var m = input.value.split('.');	
	beforeDecimal = m[0]; 
	afterDecimal = m[1]; 
	afterDecimal = afterDecimal.substring(0, 1);
	if(afterDecimal <= 3){
		afterDecimal = '30';
	}else{
		afterDecimal = '00';
	}
    input.value = beforeDecimal + '.' + afterDecimal;

   /* var nStr = input.value + '';
    nStr = nStr.replace( /\,/g, "");
    var x = nStr.split( '.' );
    var x1 = x[0];

    var x2 = x.length > 1 ? '.' + x[1] : '';
    var rgx = /(\d+)(\d{3})/;
    while ( rgx.test(x1) ) {
        x1 = x1.replace( rgx, '$1' + '.' + '$2' );
    }
	
	
    input.value = x1 + x2;*/

}
