jQuery(document).ready(function(){
	
	// ---------- //
	jQuery('.form_section_title').click(function(){
		alert("adasd");
		section = $(this).attr('data-item');
		$('#'+section).slideToggle(500,function(){
			$('#'+section+'_arrow').toggleClass("icon_rotate");
		});
		
	});
	// --------- //
	
	jQuery('.form_subsection_title').click(function(){
		section = $(this).attr('data-item');
		$('.'+section).slideToggle(500,function(){
			$('#'+section+'_arrow').toggleClass("icon_rotate");
		});
		
	});
	
	//-------//
	jQuery('.form_subsection_title2').click(function(){
		section = $(this).attr('data-item');
		$('.'+section).slideToggle(500,function(){
			$('#'+section+'_arrow').toggleClass("icon_rotate");
		});
		
	});
	
	//-------//


	
	
	
	
	
});

function addPrefix(obj, text){
	if(obj.value.length>0){
	obj.value = text+obj.value;	
	}
}
function removePrefix(obj){
	if(obj.value.length > 0){
		obj.value = obj.value.replace("City2Shore ", "");
	}
}
function convert_edit(i){
	form_id = 'c2s-broker-edit-view';
	if(i>1){
		form_id = form_id+'--'+i;
	}
	$("#"+form_id).each(function(){
	    $(this).find('select').removeClass('input_disabled').addClass('select-xlarge uniform form-select'); //<-- Should return all input elements in that specific form.
	    $(this).find('input').removeClass('input_disabled').addClass('form_text'); //<-- Should return all input elements in that specific form.
	    
	});
}

function click_tabs(obj_id){

		section = $("#"+obj_id).attr('data-item');
		$('.form_sections').hide();
		//$('.form_section_tab').find('.selected').removeClass('form_section_tab selected').addClass('form_section_tab');
		$('.selected').removeClass('form_section_tab selected').addClass('form_section_tab');
		$("#"+obj_id).addClass('selected');
		$('#'+section).show();
		/*$('#'+section).slideToggle(500,function(){
//			$('#'+section+'_arrow').toggleClass("icon_rotate");
		});*/
		
}