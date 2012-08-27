; This is a conceptual model of generating HTML in Scheme.

; This is an idea I had years ago.  I think it has been invented many times, but my
; improvement is to do it without requiring quotation marks for the strings.  It's
; easy in CL using "rest" but let's see if we can make it work in Scheme with macros
; instead...

(html
	(head
		(meta (http-equiv (Content-Type content=text/html; charset=utf-8)))

		; Note how quotation marks are unneeded around the string; string is processed as a list.
		(title This is the Title))
	(body
		(h1 This is a heading.)
		(p This is a paragraph.)
		(p This is a (b paragraph with (i embedded markup)).)))

; simplest implementation

(define html
	(lambda (l)
		(display (string-append "<html>" l "</html>"))))

