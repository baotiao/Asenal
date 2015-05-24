(define one-through-four (list 1 2 3 4))

(define (list-ref items n)
  (if (= n 0)
      (car items)
      (list-ref (cdr items) (- n 1))))
(define squares (list 1 4 9 16 25))
(list-ref squares 3)

(define (length items)
  (if (null? items)
      0
      (+ (length (cdr items)) 1)))
(define odds (list 1 3 5 7))
(length odds)

(append squares odds)

(define (last-pair items)
  (if (= (length items) 1)
    items
    (last-pair (cdr items))))
(last-pair (list 23 72 149 34))

(define (store-reverse items ans)
  (if (null? items)
    ans
    (store-reverse (cdr items) (cons (car items) ans))))

(define (reverse items)
  (store-reverse items (list)))

(reverse (list 1 2 3 4 5))

(define (reverse1 items)
  (if (null? items)
    0
    (cons (reverse1 (cdr items)) (car items))))

(reverse1 (list 1 2 3 4 5))


(define (map proc items)
  (if (null? items)
    ()
    (cons (proc (car items)) (map proc (cdr items)))))
(map abs (list -10 2.5 -11.6 17))
(map (lambda (x) (* x x)) (list 1 2 3 4))

(define (scale-list items factor)
  (map (lambda(x) (+ x factor)) items))
(scale-list (list 1 2 3 4) 10)

(define (add x)
  (+ x 10))

(define (scale items factor)
  (map add items))

(scale (list 1 2 3 4) 10)

(define deriv 
  (lambda (f)
    (lambda (x)
      (/ (- (f (+ x dx))
            (f x))
         dx))))

(define (same-variable? v1 v2)
  (and (variable? v1) (variable? v2) (eq? v1 v2)))
(same-variable? 10 10)

(define (make-sum a1 a2) (list '+ a1 a2))
(define (make-product m1 m2) (list '* m1 m2))


(define balance 100)

(define (withdraw amount)
  (if (>= balance amount)
      (begin (set! balance (- balance amount)) balance)
      "Insufficient funds"))

(withdraw 10)
(withdraw 20)


(define new-withdraw
  (let ((balance 100))
    (lambda (amount)
      (if (>= balance amount)
          (begin (set! balance (- balance amount)) balance)
          "Insufficient funds"))))


(new-withdraw 20)

(let ((x 100) (y 10)) (+ x y))
(let ((x 1) (y 2)) (+ x y))

(define (make-withdraw balance)
  (lambda (amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "insufficient funds")))

(define W1 (make-withdraw 100)) ;这里define定义一个W1, 这里定义的时候. 可以这么理解,定义的时候就可以直接有参数
(W1 50) ;这里define 结尾可以有一个函数, 那么 (W1 50) 就默认执行组后这个lambda 函数

(define W2 (make-withdraw 200))
(W2 100)
(W2 30)
(W1 1)

(define w new-withdraw)
(w 20)



(define (mk ba) (begin (define (add-n) (+ ba 1)) balance) add-n)
(define ac (mk 100))
(ac)


(define (make-accumulator sum)
  (lambda (num) (begin (set! sum (+ sum num)) sum)))
(define A (make-accumulator 5))
(A 10)
(A 10)
  

;(define (make-account balance passwd)
;  (define (withdraw amount)
;    (if (>= balance amount)
;        (begin (set! balance (- balance amount)) balance)
;        "Insufficient funds"))
;  (define (deposit amount)
;    (set! balance (+ balance amount)) balance)
;  (define (dispatch p m)
;    (cond ((and (eq? m 'withdraw)  (eq? p 'czz)) withdraw)
;          ((eq? m 'deposit) deposit)
;          ;(else (display "Unknow request -- MAKE-ACCOUNT"))))
;  dispatch) ;这个define最后的函数是 dispatch, 

;(define acc (make-account 100)) ;所以define acc 是 make-account后, 默认执行的是最后这个dispatch这个方法
;((acc 'withdraw) 50)
;(define acc (make-account 100 'czz))
;((acc 'czz 'withdraw) 40)

;(define rand 
;  (let ((x random-init))
;    (lambda () (set! x (rand-update x)) x)))

(define (make-simplified-withdraw balance)
  (lambda (amount)
    (set! balance (- balance amount))
    balance))

(define W (make-simplified-withdraw 25))
(W 20)
(W 10)

(define (make-decrementer balance)
  (lambda (amount)
    (- balance amount)))

(define D (make-decrementer 25))
(D 20)
(D 10)

((make-simplified-withdraw 25) 20)

(define D1 (make-decrementer 25))
(define D2 (make-decrementer 25))

(D1 20)

(define (factorial n)
  (define (iter product counter)
    (if (> counter n)
        product
        (iter (* counter product)
              (+ counter 1))))
  (iter 1 1))
