// UI Script to Add Collapsed Dividers in Perch Admin 
// Add this script to /perch/addons/plugins/ui/
// Download Arrive.min.js and also put it in /perch/addons/plugins/ui/ .

// ABOUT: Arrive.js 
// will check if elements are already added to the Dom 
// GitHub https://github.com/uzairfarooq/arrive

// TODO:
// - Only hide empty field, not filled ones.
// - Add CSS class, to be able to distinguish pre-collapsed fields via CSS  


<script type="text/javascript" src="/perch/addons/plugins/ui/arrive.min.js"></script>
<script> 

// If the element to be inserted by Perch has indeed been inserted ..
$(document).arrive("div.divider-collapse-zone", function() {
    // Finding the elements with an attribute divider-before starting with "collapse|"
    $metaDividerStart = $('.divider:contains("collapse-start|")');
    $metaDividerEnd   = $('.divider:contains("collapse-end|")');

    if ($metaDividerStart.length)
    { 
        // Add the perch class which changes the arrow SVG -and-
        //  set the next() div to display:none, 
        //  just like the standard Perch_init_editors behaviour - so standard behaviour can take over after initial collapse.
        $metaDividerStart.addClass('divider-collapsed').next().css('display', 'none');
        $metaDividerEnd.css('display', 'none');
        // Remove the keyword 'collapse|' individually from each of the Perch-dividers
        $metaDividerStart.each(function(i, divider){ 
            var newHTML = $('div', $(divider)).html().replace('collapse-start|', '');
            $('div', $(divider)).html(newHTML);                         
        })
    }  
});
</script>
