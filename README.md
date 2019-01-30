Translated Node Block
=====================

This is a simple module that plugs a hole in backdrop where the existing
content block does not support loading translated content.

It will load the translated version of a given node, in the current language
of the site, regardless of the node selected. If no translation is found, then
the node given is displayed.

A new block will be available named "Existing content (translated)" that works
just like the original block.

Note
====

This module is intended as a stop-gap measure until the core block supports
translation as well.
