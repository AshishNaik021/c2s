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
