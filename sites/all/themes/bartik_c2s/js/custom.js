$(document).ready(function() {
		
$("#user_photo").click(function(){
	$("#user_menu").toggle();
	
});
		
		$('#block-menu-menu-secondary-menu ul li span a.active').parent('span').parent('li').addClass('active');
		
		$('#calendar').fullCalendar({
		
			// US Holidays
			events: 'http://www.google.com/calendar/feeds/indian__en%40holiday.calendar.google.com/public/basic',
			
			eventClick: function(event) {
				// opens events in a popup window
				window.open(event.url, 'gcalevent', 'width=700,height=600');
				return false;
			},
			
			loading: function(bool) {
				if (bool) {
					$('#loading').show();
				}else{
					$('#loading').hide();
				}
			}
			
		});
		
		$('#edit-search-block-form--2').focus(function() {
		$(this).animate({width: "215"}, 300 );	
		$(this).val('')
		});

		$('#edit-search-block-form--2').blur(function() {
				$(this).animate({width: "100"}, 300 );
		});
		
		var href = document.location.href;
		var hrefval=href.substr(href.lastIndexOf('/') + 1);

		if(hrefval == 'intranet' || hrefval == 'intranet#')
			{
				$('h1#page-title').css('display', 'none');
				$('.tabs').css('display', 'none');
				
				
			}
			
		
	});

function search_employee(){
	var s_type = $('input[type="radio"]:checked').val();
	var s_value = $('input[type="textfield"]').val();

	
	if(s_type == 'ID'){
		if(s_value == ''){
		alert("Please Enter Employee ID or Name to Search Employee.");
		} else {	
			regExp = "^\\d+$";
			if (s_value.match(regExp)) {
				location.href = 'search-result?s_type='+s_type+'&s_value='+s_value;
			} else {
				alert("Please enter valid Employee ID.");
			}
		}
	} else {
		if(s_value == ''){
		alert("Please Enter Employee ID or Name to Search Employee.");
		} else {
			var regex = /^[a-zA-Z ]*$/;
			if (regex.test(s_value)) {
				location.href = 'search-result?s_type='+s_type+'&s_value='+s_value;
			} else {
				alert("Please enter valid employee name.");
			}
		}
	}
	
	
}