<div class="region region-featured">
    <div id="block-menu-menu-secondary-menu" class="block block-menu">
        <div class="content">
            <ul class="menu">
                <?php
                global $base_path;
                //print $base_path;
                //  var_dump($menuslist);
                $cnt = count($menuslist);
                $first = '';
                $last = '';
                $i=0;
                foreach ($menuslist as $value){
                     $active = '';
                       $i++;
                    //if($value['link']['access'] == TRUE) {
                    if($_GET['q'] == $value['link']['href']) {
                        $active = "active-trail active";
                    }
                    ?>
                    <?php if ($i == 0) { //for first item?>
                        <li class="first leaf <?php print $active; ?>"><span class="menu-link-title"><a href="<?php print $base_path.$value['link']['href']; ?>" title="" class="active-trail active"><?php print $value['link']['title']; ?></a></span><span class="menu-link-subtitle menu-link-subtitle-below active-trail"><?php print $value['link']['options']['attributes']['title']; ?></span></li>
                    <?php } else if ($i == $cnt) { // for last item ?>
                        <li class="last leaf <?php print $active; ?>"><span class="menu-link-title"><a href="<?php print $base_path.$value['link']['href']; ?>" title="" class="active-trail active"><?php print $value['link']['title']; ?></a></span><span class="menu-link-subtitle menu-link-subtitle-below active-trail"><?php print $value['link']['options']['attributes']['title']; ?></span></li>
                    <?php } else { // for middle items?>     
                        <li class="leaf <?php print $active; ?>"><span class="menu-link-title"><a href="<?php print $base_path.$value['link']['href']; ?>" title="" class="active-trail active"><?php print $value['link']['title']; ?></a></span><span class="menu-link-subtitle menu-link-subtitle-below active-trail"><?php print $value['link']['options']['attributes']['title']; ?></span></li>
                    <?php } ?>            
                    <?php //}
                   
                }
                ?>              
            </ul>  
        </div>
    </div>
    <div id="block-block-8" class="block block-block">
       
            <?php if(in_array('System Admin', $useripca->roles)){?>
            <div class="content-btn">
             <p><a href="<?php print $base_path; ?>pms/system-admin">MANAGE HRMS</a></p>
            </div>
            <?php } ?>  
        
            <?php if(in_array('Normal User', $useripca->roles)){?>
             <div class="content-btn1">
                <p><a href="<?php print $base_path; ?>pms/pms-dashboard">HRMS DASHBOARD</a></p>
            </div>
            <?php } ?>
    </div>
</div>