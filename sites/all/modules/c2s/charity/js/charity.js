
	function convert_to_edit(form_id){
		$("#"+form_id).each(function(){
			$(this).find('select').removeClass('input_disabled').addClass('select-xlarge uniform form-select'); //<-- Should return all input elements in that specific form.
			$(this).find('select').prop( "disabled", false ) //<-- Should return all input elements in that specific form.
			$(this).find('select').prop( "required", true ) //<-- Should return all input elements in that specific form.
			$(this).find('input').removeClass('input_disabled').addClass('input-mini'); //<-- Should return all input elements in that specific form.
			$(this).find('input').prop( "disabled", false ) //<-- Should return all input elements in that specific form.
			$(this).find('input submit').prop( "display", 'block' ) //<-- Should return all input elements in that specific form.
			$('#c2s-charity-view-edit .form-submit').show() //<-- Show Submit Button
		});
		$('input[name="edit_view"]').val('edit');
	}


	function convert_to_view(form_id){
		$("#"+form_id).each(function(){
			$(this).find('select').removeClass('select-xlarge uniform form-select').addClass('input_disabled'); //<-- Should return all input elements in that specific form.
			$(this).find('input').removeClass('input-mini').addClass('input_disabled'); //<-- Should return all input elements in that specific form.
			$(this).find('input').prop( "disabled", true ) //<-- Should return all input elements in that specific form.
			$('.form-submit').hide() //<-- Hide Submit Button
		});
	}
