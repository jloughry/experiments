;; Notes on http://mvanier.livejournal.com/2897.html

(define (factorial n)
	(if (= n 0)
		1
		(* n (factorial (- n 1)))))

(define fact
	(lambda (n)
		(if (= n 0)
			1
			(* n (factorial (- n 1))))))

(define almost-factorial
	(lambda (f)
		(lambda (n)
			(if (= n 0)
				1
				(* n (f (- n 1)))))))

(define identity (lambda (x) x))

(define factorial0 (almost-factorial identity))

(define factorial1
	(almost-factorial factorial0))

(define factorial2
	(almost-factorial factorial1))

(define factorial3
	(almost-factorial factorial2))

(define factorial4
	(almost-factorial factorial3))

(define factorial5
	(almost-factorial factorial4))

