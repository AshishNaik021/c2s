

<div id="block-user-login" class="block block-user">

<h2>User Custom login</h2>

<div class="content">
<form action="/c2s/node?destination=node" method="post" id="user-login-form" accept-charset="UTF-8"><div><div class="form-item form-type-textfield form-item-name">
<label for="edit-name">Username <span class="form-required" title="This field is required.">*</span></label>
<input type="text" id="edit-name" name="name" value="" size="15" maxlength="60" class="form-text required">
</div>
<div class="form-item form-type-password form-item-pass">
<label for="edit-pass">Password <span class="form-required" title="This field is required.">*</span></label>
<input type="password" id="edit-pass" name="pass" size="15" maxlength="128" class="form-text required">
</div>
<div class="item-list"><ul><li class="first last"><a href="/c2s/user/password" title="Request new password via e-mail.">Request new password</a></li>
</ul></div><input type="hidden" name="form_build_id" value="form-qnTbyT_LWdmgS7tkFrzCn-mCm3fkK39UJJlT28p-jLU">
<input type="hidden" name="form_id" value="user_login_block">
<fieldset class="captcha form-wrapper"><legend><span class="fieldset-legend">CAPTCHA</span></legend><div class="fieldset-wrapper"><div class="fieldset-description">This question is for testing whether or not you are a human visitor and to prevent automated spam submissions.</div><input type="hidden" name="captcha_sid" value="26">
<input type="hidden" name="captcha_token" value="0237d409e3e1dc1528a2557fbf42d23c">
<img typeof="foaf:Image" src="/c2s/image_captcha?sid=26&amp;amp;ts=1441970725" width="180" height="60" alt="Image CAPTCHA" title="Image CAPTCHA"><div class="form-item form-type-textfield form-item-captcha-response">
<label for="edit-captcha-response">What code is in the image? <span class="form-required" title="This field is required.">*</span></label>
<input type="text" id="edit-captcha-response" name="captcha_response" value="" size="15" maxlength="128" class="form-text required" autocomplete="off">
<div class="description">Enter the characters shown in the image.</div>
</div>
</div></fieldset>
<div class="form-actions form-wrapper" id="edit-actions"><input type="submit" id="edit-submit" name="op" value="Log in" class="form-submit"></div></div></form>  </div>
</div>