<div id="main" style="max-width: 100% !important; width: 100% !important;">
    <!-- <div id="header"> <img src="<?php //print $front_page . path_to_theme(); ?>/images/top.png" /> </div> -->
    <?php drupal_set_title('Welcome to Ipca Intranet Portal');?>
    <div id="header" style="background-color: #10aff1; padding: 30px 0;"> <div id="front_heading"><?php if( $site_name )print $site_name?></div> <div id="front_heading_small"><?php if( $site_slogan )print $site_slogan ?></div></div>
    <div id="landing-middle">
         <?php print $messages; ?>
        <div class="middle-left"> 
            <div id="login-form">  
                <div id="login-form-heading">
                <h4>Use Login</h4>
                </div>
                <div id="user_login_ipca"> </div>
                <?php
                    $ulogin = drupal_get_form('user_login');
                    $log    = drupal_render($ulogin);
                    print $log; ?> 
                <div class="login_forgot_pass">Forgot password</div>
            </div>
        </div> <!-------------middle-left end------------->
        <div class="middle-right">  </div>
     </div> 
    <div id="front-footer" style="margin-top: 0%;  width: 64%; padding-bottom: 0; position: absolute; bottom: 0;">
<!--        <div class="important-features">
            <div class="imp-h"> Important Features </div>
            <ul>
                <li><div class="img"> <img src="<?php //print $front_page . path_to_theme(); ?>/images/emp1.png"  /> </div>
                    <div> Employee Induction </div> </li>
                <li><div class="img"> <img src="<?php //print $front_page . path_to_theme(); ?>/images/bar.png"  /> </div>
                    <div> Employee Progression</div> </li>
                <li><div class="img"> <img src="<?php //print $front_page . path_to_theme(); ?>/images/emp2.png"  /> </div>
                    <div> Employee Separation </div> </li>
                <li><div class="img"> <img src="<?php //print $front_page . path_to_theme(); ?>/images/gr.png"  /> </div>
                    <div> Training & Development </div> </li>
                <li><div class="img"> <img src="<?php //print $front_page . path_to_theme(); ?>/images/pay.png"  /> </div>
                    <div> Integrated Payroll Process </div> </li>
                <li><div class="img"> <img src="<?php //print $front_page . path_to_theme(); ?>/images/tr.png"  /> </div>
                    <div> Corporate Travel Management </div> </li>
            </ul>
        </div>-->

<div class="footer_image"><img src="<?php print $front_page . path_to_theme(); ?>/images/ipca_footer.png"  style="width: 100% !important; height: auto;" /></div>
    </div> 

</div>

<!--<div class="front_main">
 <div class="front_header">
  Ipca Intranet portal
 </div>
            
            <div class="front_left_right">
                        <div class="front_leftsidebar">
                                        <div class="front_user_login_box">
                                                        <div class="front_user_login_ipca">
                                                                <div class="front_user_login">User login</div>
                                                                <div class="front_ipca_logo"><img src="" /></div>
                                                        </div>

                                             <?php                                             
                                             $form['pass']['#title']=$form['name']['#title']='';
                                             $form['pass']['#required']=$form['name']['#required']=FALSE;
                                             $form['pass']['#theme_wrappers']=$form['name']['#theme_wrappers']=array();
                                             $form['pass']['#attributes']=array('placeholder'=>'Password');
                                             $form['name']['#attributes']=array('placeholder'=>'Email Address');
                                             
                                             ?>                              
                                        <div class="user_image"> </div>UserName
                                        <?php //print drupal_render($form['name']);?>
                                        <br>
                                        <div class="user_password"> </div>Password
                                        <?php //print drupal_render($form['pass']);?>
                                        <br>
                                        <div class="forgot_pass"><a href="">Forgot your password?</a></div>
                                        <input type="submit" id="edit-submit" name="op" value="Log in" class="form-submit">
                                        <?php                                            
                                           // print drupal_render($form['actions']);
                                            //print drupal_render($form['form_build_id']);
                                           // print drupal_render($form['form_id']);
                                        ?>
                                

                                        </div>
                        </div>
                
                

                <div class="front_rightsidebar"><img src="../sites/all/themes/ipca_portal/images/banner1.png" /></div>
                
                <div class="clear_both"> </div>
            </div>
 
</div>-->
