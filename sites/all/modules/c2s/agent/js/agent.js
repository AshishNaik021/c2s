function convert_edit(i){
	form_id = 'c2s-agent-view';
	$("#"+form_id).each(function(){
		
	    $(this).find('select').removeClass('input_disabled').addClass('select-xlarge uniform form-select'); //<-- Should return all input elements in that specific form.
	    $(this).find('input').removeClass('input_disabled').addClass('form_text'); //<-- Should return all input elements in that specific form.
	    $(this).find('input').removeAttr('disabled'); //<-- Should return all input elements in that specific form.
	    $(this).find('select').removeAttr('disabled'); //<-- Should return all input elements in that specific form.
	});
}
function click_tabs_add(obj_id){
	section = $("#"+obj_id).attr('data-item');
	$(".form_sections").hide();
	$('.selected').removeClass('form_section_tab selected').addClass('form_section_tab');
	$("#"+obj_id).addClass('selected');
	$('#'+section).show();
}


function click_tabs_agent(obj_id){
		$(".broker_form").hide();
		section = $("#tab_"+obj_id).attr('data-item');
		$('.form_sections').hide();
		//$('.form_section_tab').find('.selected').removeClass('form_section_tab selected').addClass('form_section_tab');
		$('.selected').removeClass('form_section_tab selected').addClass('form_section_tab');
		$("#tab_"+obj_id).addClass('selected');
		$('#'+section).show();
		/*$('#'+section).slideToggle(500,function(){
//			$('#'+section+'_arrow').toggleClass("icon_rotate");
		});*/
		
}