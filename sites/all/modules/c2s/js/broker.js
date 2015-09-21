jQuery(document).ready(function(){
	
	// ---------- //
	jQuery('.form_section_title').click(function(){
		section = $(this).attr('data-item');
		$('#'+section).slideToggle(1000,function(){
			$('#'+section+'_arrow').toggleClass("icon_rotate");
		});
		
	});
	// --------- //
	
	jQuery('.form_subsection_title').click(function(){
		section = $(this).attr('data-item');
		$('.'+section).slideToggle(1000,function(){
			$('#'+section+'_arrow').toggleClass("icon_rotate");
		});
		
	});
	
	//-------//
	jQuery('.form_subsection_title2').click(function(){
		section = $(this).attr('data-item');
		$('.'+section).slideToggle(1000,function(){
			$('#'+section+'_arrow').toggleClass("icon_rotate");
		});
		
	});
	
	
	
});
