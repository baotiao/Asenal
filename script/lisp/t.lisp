;(defun our-member (obj lst)
;  (if (null lst)
;    nil
;    (if (eql (car lst) obj)
;      lst
;      (our-member obj (cdr lst)))))
;
;;(print (our-member '1 '(2 3 4 1 4 5 44)))
;
;(format t "~A plus ~A equals ~A.~%" 2 3 (+ 2 4))
;
;(defun askem (string)
;  (format t "~A" string)
;  (read))
;(format t "(askem "How old are you? ")")
(print ((lambda (x y) (+ x y)) 5 6))

(defun my-abs (x)
  (if (> x 0)
    (x)
    (- x)))

(print (my-abs -10))
