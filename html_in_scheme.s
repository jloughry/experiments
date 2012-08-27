; This is a conceptual model of generating HTML in Scheme.

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

