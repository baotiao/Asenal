----------------------------- MODULE CoffeeBean -----------------------------

EXTENDS Naturals, Integers, TLC

CONSTANT C

VARIABLE w, b

TypeOK == /\ w \in Nat
          /\ b \in Nat
          

                    
PickSame == \/ IF w >= 2
               THEN /\ w' = w - 2
                    /\ b' = b + 1
               ELSE /\ w' = w
                    /\ b' = b
            \/ IF b >= 2
               THEN /\ b' = b - 1
                    /\ w' = w
               ELSE /\ w' = w
                    /\ b' = b
               
PickDiff == IF /\ w >= 1 
               /\ b >= 1
            THEN /\ w' = w - 1
                 /\ b' = b
            ELSE /\ w' = w
                 /\ b' = b
            

Init == /\ w = RandomElement(1..10)
        /\ b = C - w

Next == PickSame \/ PickDiff



=============================================================================
\* Modification History
\* Last modified Wed Jun 06 02:51:20 CST 2018 by baotiao
\* Created Tue Jun 05 17:57:37 CST 2018 by baotiao

