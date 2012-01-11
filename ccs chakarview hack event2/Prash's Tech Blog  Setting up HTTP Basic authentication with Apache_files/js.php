id = "prashanthgedde";style = "1";if(showme==null) var showme='y';
if(st==null)     var st='img';    // st means show-type

v = navigator.appName;
c=0;
if (v != "Netscape") c = screen.colorDepth;
else c = screen.pixelDepth;
s = screen.width+"x"+screen.height;
t = escape(document.title);
var f = "";
if (typeof(pp_frames) != "undefined")
	if (pp_frames)
		f = top.document.referrer;

if ((f == "") || (f == "[unknown origin]") || (f == "unknown") || (f == "undefined"))
	if (document["parent"] != null) 
		if (parent["document"] != null) // ACCESS ERROR HERE!
			if (parent.document["referrer"] != null) 
				if (typeof(parent.document) == "object")
					f = parent.document.referrer; 
if ((f == "") || (f == "[unknown origin]") || (f == "unknown") || (f == "undefined"))
	if (document["referrer"] != null) 
		f = document.referrer;
if ((f == "") || (f == "[unknown origin]") || (f == "unknown") || (f == "undefined"))
	f = "";
f = escape(f);
r="?id="+id+"&referer="+f+"&r="+s+"&c="+c+"&showme="+showme+"&st="+st+"&title="+t+"&style="+style;
if(jslogid==null) var jslogid = 0;
else r = r + "&jslogid="+jslogid;

function getElement(id) {
    if (typeof(id) != 'string') return id;
    if (document.getElementById) {
	return document.getElementById(id);
    } else if (document.all) {
	return document.all[id];
    } else {
	return null;
    }
}

var link = getElement('bclink');
var html = getElement('bccount');

    if (v != "Microsoft Internet Explorer") {
	r = r+"&url="+document.URL; // $HTTP_REFERER problem with NS,...
    }
	
if (link != null && html != null) {

	rand = Math.round(1000*Math.random());
	r = r+"&b="+rand;  //force the page to load the IMG

	link.href = 'http://BlogCounter.com/';

	html.innerHTML = '';
	html.innerHTML = '<img src="http://BlogCounter.com/bc/log.php'+r+'" alt="BlogCounter.com - Free counter for Weblogs" border="0" width="80" height="15">';
}
