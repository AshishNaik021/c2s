
            
                                    <div class="front_leftsidebar">
                                        <div class="front_user_login_box">
                                                        <div class="front_user_login_ipca">
                                                                <div class="front_user_login">User Login</div>
                                                                <div class="front_ipca_logo"><img src="../sites/all/themes/ipca_portal/images/IPCA-login-logo.jpg" /></div>
                                                        </div>

                                             <?php
                    
                                                    // print_r($ulogin);
                                                        $form['pass']['#title']=$form['name']['#title']='';
                                                        $form['pass']['#required']=$form['name']['#required']=FALSE;
                                                        $form['pass']['#theme_wrappers']=$form['name']['#theme_wrappers']=array();
                                                        $form['pass']['#attributes']=array('placeholder'=>'Password');
                                                        $form['name']['#attributes']=array('placeholder'=>'User ID');

                                        //print $log; ?> 
                                                <div class="ipca_user_main">
                                                        <div class="user_image">&nbsp;</div>
                                                        <div class="ipca_user_input"><?php print drupal_render($form['name']);?></div>
                                                </div> 
                                                        <br>
                                                 <div class="ipca_user_main">
                                                        <div class="user_password">&nbsp;</div>
                                                        <div class="ipca_user_input"><?php print drupal_render($form['pass']);?></div>
                                                 </div>
<?php
    print drupal_render($form['captcha']); ?>

                                                        <div class="forgot_pass"><a href="">Forgot your password?</a></div>
                                                        <input type="submit" id="edit-submit" name="op" value="Login" class="form-submit">
                                                        <?php                                            
                                                        // print drupal_render($form['actions']);
                                                        print drupal_render($form['form_build_id']);
                                                        print drupal_render($form['form_id']);
                                                        ?>
                                                      
                                        </div>
                                </div>
                
                

                

