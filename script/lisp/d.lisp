;(defun show-squares (start end)
;  (do ((i start (+ i 1)))
;      ((> i end) 'done)
;    (format t "~A ~A~%" i (* i i))))
;
;(print (show-squares 2 4))
;
;(defun show-sq (i end)
;  (if (> i end)
;    'done
;    (progn
;      (format t "~A ~A~%" i (* i i))
;      (show-sq (+ i 1) end))))
;
;(show-sq 2 5)

;(defun four (lst cnt)
;  (if (eql cnt 1)
;      (car lst)
;    (progn 
;      (print (car lst))
;      (format t "cnt ~A" cnt)
;      (four (cdr lst) (- cnt 1)))))
;
;(print (four '(1 2 3 4 3) 4))
;
;(defun greater (x y)
;  (if (> x y)
;    x
;    y))
;
;(print (greater 3 5))

;(defun print-point (num)
;  (if (eql num 0)
;    'done
;    (progn
;      (print ".")
;      (print-point (- num 1)))))
;
;(print-point 10)
;
;(defun pp (num)
;  (do ((i 0 (+ i 1)))
;      ((> i num)
;       'done)
;      (format t ".")))
;
;(pp 10)

;(print (function +))
;(print (apply #'+ '(1 2 3)))

;(defun sum-int (a b)
;  (if (> a b)
;    0
;    (+ a 
;       (sum-int (+ a 1) b))))
;
;(print (sum-int 2 4))
;
;(defun sq (a) (* a a))
;(defun bt (i) (/ 1 (* i (+ i 2))))
;
;(defun sum-sq (a b)
;  (if (> a b)
;    0
;    (+ (bt a)
;       (sum-sq (+ a 1) b))))
;
;
;(print (sum-sq 2 3))


(defun sum (term a next b)
  (if (> a b)
    0
    (+ (term a)
       (sum term (next a) next b))))

(defun sum-i (a b)
  (sum (lambda (i) (/ 1 (* i (+ i 2)))) a (lambda (i) (i + 4)) b))

(print (sum-i 1 4))


