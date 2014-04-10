;;; (length '()) is 0
;;; (length '(a b c)) is 3

(define length
  (lambda (l)
    (if (null? l)
      0
      (+ 1 (length (cdr l))))))

