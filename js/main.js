/*
 * @file onepage.js
 *
 * Main file containing functionality needed for onepage functionality.
 */

// cached scroll position
latestKnownScrollY = 0;

/*
 * Function to check for 2D/3D transformation support. Using 3D transformations
 * drastically reduces repaints and should therefore be used when available.
 *
 * @source https://gist.github.com/lorenzopolidori/3794226
 */
function checkForTransform(check3D) {
  if (!window.getComputedStyle) {
    return false;
  }

  var el = document.createElement('p'),
    has3d,
    transforms = {
      'webkitTransform':'-webkit-transform',
      'OTransform':'-o-transform',
      'msTransform':'-ms-transform',
      'MozTransform':'-moz-transform',
      'transform':'transform'
    };

  // Add it to the body to get the computed style.
  document.body.insertBefore(el, null);

  for (var t in transforms) {
    if (el.style[t] !== undefined) {
      if (check3D) {
        el.style[t] = "translate3d(1px,1px,1px)";
      } else {
        el.style[t] = "translate(1px,1px)";
      }
      has3d = window.getComputedStyle(el).getPropertyValue(transforms[t]);
    }
  }

  document.body.removeChild(el);

  return (has3d !== undefined && has3d.length > 0 && has3d !== "none");
}

/*
 * Function to check whether an element can be seen (vertically).
 */
function isScrolledIntoView(elem) {
  var docViewTop = latestKnownScrollY;
  var docViewBottom = docViewTop + jQuery(window).innerHeight();
  var elemTop = jQuery(elem).offset().top;
  var elemBottom = elemTop + jQuery(elem).height() + jQuery(elem).css("padding-bottom");
  return !(elemBottom < docViewTop || elemTop > docViewBottom);
}

/*
 * Main update function for parallax effect, menu links and
 * history updates.
 */
function update() {
  var currentScrollY = latestKnownScrollY;

  // parallax
  jQuery(".bgwrapper").each(function () {
    var yPos = currentScrollY - jQuery(this).offset().top;
    if (jQuery(this).find(".parallaxwrapper").length > 0 && isScrolledIntoView(this)) {
      if (has3D) {
        jQuery(this).find(".parallaxwrapper").css({"transform": "translate3d(0, " + yPos * 0.8 + "px, 0)"});
      } else if (has2D) {
        jQuery(this).find(".parallaxwrapper").css({"transform": "translate(0, " + yPos * 0.8 + "px)"});
      } else {
        jQuery(this).find(".parallaxwrapper").css({marginTop: yPos * 0.8});
      }
    }
  });

  // menu
  var current = jQuery(".page").eq(0).attr("id");
  for (var i = 0; i < jQuery(".page").length; i++) {
    var obj = jQuery(".page").eq(i);
    if (obj.offset().top <= currentScrollY && isScrolledIntoView(obj)) {
      var current = obj.attr("id");
    }
  }
  if (!jQuery('ul.nav a[href=#'+current+']').hasClass('active')) {
    jQuery('ul.nav li').removeClass('active');
    jQuery('ul.nav li a').removeClass('active');
    jQuery('ul.nav a[href=#'+current+']').parent().addClass('active');
    jQuery('ul.nav a[href=#'+current+']').addClass('active');
  }

  if (current == jQuery(".page").eq(0).attr("id")) {
    if (!jQuery("#navbar").hasClass("front")) {jQuery("#navbar").addClass("front");}
  } else {
    if (jQuery("#navbar").hasClass("front")) {jQuery("#navbar").removeClass("front");}
  }

  // change URL
  if (current != window.location.hash.slice(1) && history && history.pushState) {
    if (current == "") {
      history.pushState({}, document.title, location.href.split("#")[0]);
    } else {
      history.pushState({}, document.title, location.href.split("#")[0] + "#" + current);
    }
  }
}

/*
 * Catches scroll event to update onepage effects.
 */
jQuery(document).ready(function () {
  if (screen.width < 768) {return;}

  has3D = checkForTransform(true);
  has2D = checkForTransform(false);

  update();

  jQuery(window).on("scroll", function () {
    latestKnownScrollY = window.pageYOffset;
    update();
  });

  /* Call update again for mousewheel to avoid
     stuttering in some browsers. */
  jQuery(window).bind("mousewheel DOMMouseScroll", function (e) {
    setTimeout(update, 16);
  });
});

/*
 * Catches clicks on anchor links and smoothly scrolls to their
 * location.
 */
jQuery(document).ready(function () {
  jQuery("a").click(function() {
    var target = jQuery(this).attr("href");
    if (target == "#") {
      target = "#" + jQuery(".page").eq(0).attr("id");
    };
    jQuery("html, body").animate({
      scrollTop: jQuery(target).offset().top
    }, Math.abs(jQuery(target).offset().top - jQuery(window).scrollTop()) / 2);
    return false;
  });
});

/*
 * Catches PageUp/PageDown key inputs to allow users to skip
 * through the seperate pages.
 */
jQuery(document).keydown(function(e) {
  var code = (e.keyCode ? e.keyCode : e.which);
  if (code == 33 || code == 34) {
    var index = 0;
    for (var i = 0; i < jQuery(".page").length; i++) {
      var posObj = jQuery(".page").eq(i).offset().top;
      var posWindow = jQuery(window).scrollTop();
      if (Math.abs(posObj - posWindow) < 30) {
        index = i;
        break;
      }
      if (posObj > posWindow) {
        if (code == 33) {
          index = i;
        } else {
          index = i - 1;
        }
        break;
      }
    }
    if (code == 33) {
      index--;
    } else {
      index++;
    }
    if (index < 0 || index >= jQuery(".page").length) {
      return;
    }
    e.stopPropagation();
    e.preventDefault();
    jQuery('html, body').animate({
      scrollTop: jQuery(".page").eq(index).offset().top
    }, Math.abs(jQuery(".page").eq(index).offset().top - jQuery(window).scrollTop()) / 2);
  }
});
