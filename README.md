# Perch Auto-collapsable Dividers

This Addon for [Perch](grabaperch.com) makes it possible for dividers to initially be collapsed. 
Normally field dividers in Perch templates are all open. This takes a lot of screenspace for fields that are not used that often.

Also you can add end-dividers. 
These end-dividers are then hidden in the admin interface. There purpose is to be able to define the end of a divider section.
Normally a divider range it from the divider to another divider or to the end of the template. With the invisible end-divider you can determine the complete range of a divider without adding unnecessary dividers.

### How to install
1. Download `Arrive.js` from https://github.com/uzairfarooq/arrive
2. Add the files `_config.inc` and `arrive.min.js` to /perch/addons/plugins/ui/
3. Add some dividers (divider-before="collapse-start|My divider text") to your template. You can also use 'divider-after' and ="collapse-end", see example code.    


### How it works
The ui script looks for a keyword ('collapse-start') in the name of the divider and inserts into the DOM, the standard Perch code to collapse the divider.
It then looks for ('collapse-end') to make that divider element invisible.

### Why using Arrive.js
The arrive.min.js is needed, because without it the script will not see the extra  
`(div class="divider-collapsed")`  
element that is added later.
I have also used a time-delay, but I think this is more stable. There also was a suggestion to make use of a custom Perch Event which adds the `div.divider-collapsed` with the code:  
 `$(window).on('Perch_Init_Editors', function(){`  
sadly I couldn't get this to work. 

### TODO   
I would like to add some code to determine if the divider fields are initially filled. And not collapse fields which are filled.  


## Example use in your Perch template file
~~~
<!-- This is a Perch Template which resides in /perch/templates/content/<mytemplate>.html -->


<!-- start of code snippet, there can be perch fields before this -->
<perch:if exists ="alineaimage"> 
    <img
      class="foto" 
      style="max-width: 374px" 
      src  ="<perch:content id="alineaimage" type="image" label="Foto" divider-before="collapse-start|Optionele foto" />"        
      alt  ="<perch:content id="FotoOms" type="text" label="Foto Omschrijving" divider-after="collapse-end|Dummy divider - End of collapse"/>" 
    /> 
</perch:if>

<!-- other perch fields might follow -->
~~~
