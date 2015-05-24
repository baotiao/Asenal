(defun mirror (s)
  (let ((len (length s)))
    (and (evenp len)
         (let ((mid (/ len 2)))
           (equal (subseq s 0 mid)
                  (reverse (subseq s mid)))))))

(print (mirror '(a b c b a)))

(defun nthmost (n lst)
  (nth (- n 1)
       (sort (copy-list lst) #'>)))
