﻿/ / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 / /   F i l e :   T u t o r i a l 0 7 . c p p 
 
 / / 
 
 / /   T h i s   a p p l i c a t i o n   d e m o n s t r a t e s   t e x t u r i n g 
 
 / / 
 
 / /   C o p y r i g h t   ( c )   M i c r o s o f t   C o r p o r a t i o n .   A l l   r i g h t s   r e s e r v e d . 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 # p r a g m a   w a r n i n g   ( d i s a b l e : 4 8 3 8 ) 
 
 # p r a g m a   w a r n i n g   ( d i s a b l e : 4 0 0 5 ) 
 
 # i n c l u d e   < w i n d o w s . h > 
 
 # i n c l u d e   < d 3 d 1 1 . h > 
 
 # i n c l u d e   < d 3 d x 1 1 . h > 
 
 # i n c l u d e   < d 3 d c o m p i l e r . h > 
 
 # i n c l u d e   < x n a m a t h . h > 
 
 # i n c l u d e   " r e s o u r c e . h " 
 
 
 
 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 / /   S t r u c t u r e s 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 s t r u c t   S i m p l e V e r t e x 
 
 { 
 
 	 X M F L O A T 3   P o s ; 
 
 	 X M F L O A T 2   T e x ; 
 
 } ; 
 
 
 
 s t r u c t   C B N e v e r C h a n g e s 
 
 { 
 
 	 X M M A T R I X   m V i e w ; 
 
 } ; 
 
 
 
 s t r u c t   C B C h a n g e O n R e s i z e 
 
 { 
 
 	 X M M A T R I X   m P r o j e c t i o n ; 
 
 } ; 
 
 
 
 s t r u c t   C B C h a n g e s E v e r y F r a m e 
 
 { 
 
 	 X M M A T R I X   m W o r l d ; 
 
 	 X M F L O A T 4   v M e s h C o l o r ; 
 
 } ; 
 
 
 
 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 / /   G l o b a l   V a r i a b l e s 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 H I N S T A N C E                                                       g _ h I n s t   =   N U L L ; 
 
 H W N D                                                                 g _ h W n d   =   N U L L ; 
 
 D 3 D _ D R I V E R _ T Y P E                                           g _ d r i v e r T y p e   =   D 3 D _ D R I V E R _ T Y P E _ N U L L ; 
 
 D 3 D _ F E A T U R E _ L E V E L                                       g _ f e a t u r e L e v e l   =   D 3 D _ F E A T U R E _ L E V E L _ 1 1 _ 0 ; 
 
 I D 3 D 1 1 D e v i c e *                                               g _ p d 3 d D e v i c e   =   N U L L ; 
 
 I D 3 D 1 1 D e v i c e C o n t e x t *                                 g _ p I m m e d i a t e C o n t e x t   =   N U L L ; 
 
 I D X G I S w a p C h a i n *                                           g _ p S w a p C h a i n   =   N U L L ; 
 
 I D 3 D 1 1 R e n d e r T a r g e t V i e w *                           g _ p R e n d e r T a r g e t V i e w   =   N U L L ; 
 
 I D 3 D 1 1 T e x t u r e 2 D *                                         g _ p D e p t h S t e n c i l   =   N U L L ; 
 
 I D 3 D 1 1 D e p t h S t e n c i l V i e w *                           g _ p D e p t h S t e n c i l V i e w   =   N U L L ; 
 
 I D 3 D 1 1 V e r t e x S h a d e r *                                   g _ p V e r t e x S h a d e r   =   N U L L ; 
 
 I D 3 D 1 1 P i x e l S h a d e r *                                     g _ p P i x e l S h a d e r   =   N U L L ; 
 
 I D 3 D 1 1 I n p u t L a y o u t *                                     g _ p V e r t e x L a y o u t   =   N U L L ; 
 
 I D 3 D 1 1 B u f f e r *                                               g _ p V e r t e x B u f f e r   =   N U L L ; 
 
 I D 3 D 1 1 B u f f e r *                                               g _ p I n d e x B u f f e r   =   N U L L ; 
 
 I D 3 D 1 1 B u f f e r *                                               g _ p C B N e v e r C h a n g e s   =   N U L L ; 
 
 I D 3 D 1 1 B u f f e r *                                               g _ p C B C h a n g e O n R e s i z e   =   N U L L ; 
 
 I D 3 D 1 1 B u f f e r *                                               g _ p C B C h a n g e s E v e r y F r a m e   =   N U L L ; 
 
 I D 3 D 1 1 S h a d e r R e s o u r c e V i e w *                       g _ p T e x t u r e R V   =   N U L L ; 
 
 I D 3 D 1 1 S a m p l e r S t a t e *                                   g _ p S a m p l e r L i n e a r   =   N U L L ; 
 
 X M M A T R I X                                                         g _ W o r l d ; 
 
 X M M A T R I X                                                         g _ V i e w ; 
 
 X M M A T R I X                                                         g _ P r o j e c t i o n ; 
 
 X M F L O A T 4                                                         g _ v M e s h C o l o r ( 0 . 7 f ,   0 . 7 f ,   0 . 7 f ,   1 . 0 f ) ; 
 
 
 
 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 / /   F o r w a r d   d e c l a r a t i o n s 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 H R E S U L T   I n i t W i n d o w ( H I N S T A N C E   h I n s t a n c e ,   i n t   n C m d S h o w ) ; 
 
 H R E S U L T   I n i t D e v i c e ( ) ; 
 
 v o i d   C l e a n u p D e v i c e ( ) ; 
 
 L R E S U L T   C A L L B A C K         W n d P r o c ( H W N D ,   U I N T ,   W P A R A M ,   L P A R A M ) ; 
 
 v o i d   R e n d e r ( ) ; 
 
 
 
 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 / /   E n t r y   p o i n t   t o   t h e   p r o g r a m .   I n i t i a l i z e s   e v e r y t h i n g   a n d   g o e s   i n t o   a   m e s s a g e   p r o c e s s i n g   
 
 / /   l o o p .   I d l e   t i m e   i s   u s e d   t o   r e n d e r   t h e   s c e n e . 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 i n t   W I N A P I   w W i n M a i n ( H I N S T A N C E   h I n s t a n c e ,   H I N S T A N C E   h P r e v I n s t a n c e ,   L P W S T R   l p C m d L i n e ,   i n t   n C m d S h o w ) 
 
 { 
 
 	 U N R E F E R E N C E D _ P A R A M E T E R ( h P r e v I n s t a n c e ) ; 
 
 	 U N R E F E R E N C E D _ P A R A M E T E R ( l p C m d L i n e ) ; 
 
 
 
 	 i f   ( F A I L E D ( I n i t W i n d o w ( h I n s t a n c e ,   n C m d S h o w ) ) ) 
 
 	 	 r e t u r n   0 ; 
 
 
 
 	 i f   ( F A I L E D ( I n i t D e v i c e ( ) ) ) 
 
 	 { 
 
 	 	 C l e a n u p D e v i c e ( ) ; 
 
 	 	 r e t u r n   0 ; 
 
 	 } 
 
 
 
 	 / /   M a i n   m e s s a g e   l o o p 
 
 	 M S G   m s g   =   {   0   } ; 
 
 	 w h i l e   ( W M _ Q U I T   ! =   m s g . m e s s a g e ) 
 
 	 { 
 
 	 	 i f   ( P e e k M e s s a g e ( & m s g ,   N U L L ,   0 ,   0 ,   P M _ R E M O V E ) ) 
 
 	 	 { 
 
 	 	 	 T r a n s l a t e M e s s a g e ( & m s g ) ; 
 
 	 	 	 D i s p a t c h M e s s a g e ( & m s g ) ; 
 
 	 	 } 
 
 	 	 e l s e 
 
 	 	 { 
 
 	 	 	 R e n d e r ( ) ; 
 
 	 	 } 
 
 	 } 
 
 
 
 	 C l e a n u p D e v i c e ( ) ; 
 
 
 
 	 r e t u r n   ( i n t ) m s g . w P a r a m ; 
 
 } 
 
 
 
 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 / /   R e g i s t e r   c l a s s   a n d   c r e a t e   w i n d o w 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 H R E S U L T   I n i t W i n d o w ( H I N S T A N C E   h I n s t a n c e ,   i n t   n C m d S h o w ) 
 
 { 
 
 	 / /   R e g i s t e r   c l a s s 
 
 	 W N D C L A S S E X   w c e x ; 
 
 	 w c e x . c b S i z e   =   s i z e o f ( W N D C L A S S E X ) ; 
 
 	 w c e x . s t y l e   =   C S _ H R E D R A W   |   C S _ V R E D R A W ; 
 
 	 w c e x . l p f n W n d P r o c   =   W n d P r o c ; 
 
 	 w c e x . c b C l s E x t r a   =   0 ; 
 
 	 w c e x . c b W n d E x t r a   =   0 ; 
 
 	 w c e x . h I n s t a n c e   =   h I n s t a n c e ; 
 
 	 w c e x . h I c o n   =   L o a d I c o n ( h I n s t a n c e ,   ( L P C T S T R ) I D I _ T U T O R I A L 1 ) ; 
 
 	 w c e x . h C u r s o r   =   L o a d C u r s o r ( N U L L ,   I D C _ A R R O W ) ; 
 
 	 w c e x . h b r B a c k g r o u n d   =   ( H B R U S H ) ( C O L O R _ W I N D O W   +   1 ) ; 
 
 	 w c e x . l p s z M e n u N a m e   =   N U L L ; 
 
 	 w c e x . l p s z C l a s s N a m e   =   L " T u t o r i a l W i n d o w C l a s s " ; 
 
 	 w c e x . h I c o n S m   =   L o a d I c o n ( w c e x . h I n s t a n c e ,   ( L P C T S T R ) I D I _ T U T O R I A L 1 ) ; 
 
 	 i f   ( ! R e g i s t e r C l a s s E x ( & w c e x ) ) 
 
 	 	 r e t u r n   E _ F A I L ; 
 
 
 
 	 / /   C r e a t e   w i n d o w 
 
 	 g _ h I n s t   =   h I n s t a n c e ; 
 
 	 R E C T   r c   =   {   0 ,   0 ,   6 4 0 ,   4 8 0   } ; 
 
 	 A d j u s t W i n d o w R e c t ( & r c ,   W S _ O V E R L A P P E D W I N D O W ,   F A L S E ) ; 
 
 	 g _ h W n d   =   C r e a t e W i n d o w ( L " T u t o r i a l W i n d o w C l a s s " ,   L " D i r e c t 3 D   1 1   T u t o r i a l   7 " ,   W S _ O V E R L A P P E D W I N D O W , 
 
 	 	 C W _ U S E D E F A U L T ,   C W _ U S E D E F A U L T ,   r c . r i g h t   -   r c . l e f t ,   r c . b o t t o m   -   r c . t o p ,   N U L L ,   N U L L ,   h I n s t a n c e , 
 
 	 	 N U L L ) ; 
 
 	 i f   ( ! g _ h W n d ) 
 
 	 	 r e t u r n   E _ F A I L ; 
 
 
 
 	 S h o w W i n d o w ( g _ h W n d ,   n C m d S h o w ) ; 
 
 
 
 	 r e t u r n   S _ O K ; 
 
 } 
 
 
 
 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 / /   H e l p e r   f o r   c o m p i l i n g   s h a d e r s   w i t h   D 3 D X 1 1 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 H R E S U L T   C o m p i l e S h a d e r F r o m F i l e ( c o n s t   W C H A R *   s z F i l e N a m e ,   L P C S T R   s z E n t r y P o i n t ,   L P C S T R   s z S h a d e r M o d e l ,   I D 3 D B l o b * *   p p B l o b O u t ) 
 
 { 
 
 	 H R E S U L T   h r   =   S _ O K ; 
 
 
 
 	 D W O R D   d w S h a d e r F l a g s   =   D 3 D C O M P I L E _ E N A B L E _ S T R I C T N E S S ; 
 
 # i f   d e f i n e d (   D E B U G   )   | |   d e f i n e d (   _ D E B U G   ) 
 
 	 / /   S e t   t h e   D 3 D C O M P I L E _ D E B U G   f l a g   t o   e m b e d   d e b u g   i n f o r m a t i o n   i n   t h e   s h a d e r s . 
 
 	 / /   S e t t i n g   t h i s   f l a g   i m p r o v e s   t h e   s h a d e r   d e b u g g i n g   e x p e r i e n c e ,   b u t   s t i l l   a l l o w s   
 
 	 / /   t h e   s h a d e r s   t o   b e   o p t i m i z e d   a n d   t o   r u n   e x a c t l y   t h e   w a y   t h e y   w i l l   r u n   i n   
 
 	 / /   t h e   r e l e a s e   c o n f i g u r a t i o n   o f   t h i s   p r o g r a m . 
 
 	 d w S h a d e r F l a g s   | =   D 3 D C O M P I L E _ D E B U G ; 
 
 # e n d i f 
 
 
 
 	 I D 3 D B l o b *   p E r r o r B l o b ; 
 
 	 h r   =   D 3 D X 1 1 C o m p i l e F r o m F i l e ( s z F i l e N a m e ,   N U L L ,   N U L L ,   s z E n t r y P o i n t ,   s z S h a d e r M o d e l , 
 
 	 	 d w S h a d e r F l a g s ,   0 ,   N U L L ,   p p B l o b O u t ,   & p E r r o r B l o b ,   N U L L ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 { 
 
 	 	 i f   ( p E r r o r B l o b   ! =   N U L L ) 
 
 	 	 	 O u t p u t D e b u g S t r i n g A ( ( c h a r * ) p E r r o r B l o b - > G e t B u f f e r P o i n t e r ( ) ) ; 
 
 	 	 i f   ( p E r r o r B l o b )   p E r r o r B l o b - > R e l e a s e ( ) ; 
 
 	 	 r e t u r n   h r ; 
 
 	 } 
 
 	 i f   ( p E r r o r B l o b )   p E r r o r B l o b - > R e l e a s e ( ) ; 
 
 
 
 	 r e t u r n   S _ O K ; 
 
 } 
 
 
 
 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 / /   C r e a t e   D i r e c t 3 D   d e v i c e   a n d   s w a p   c h a i n 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 H R E S U L T   I n i t D e v i c e ( ) 
 
 { 
 
 	 H R E S U L T   h r   =   S _ O K ; 
 
 
 
 	 R E C T   r c ; 
 
 	 G e t C l i e n t R e c t ( g _ h W n d ,   & r c ) ; 
 
 	 U I N T   w i d t h   =   r c . r i g h t   -   r c . l e f t ; 
 
 	 U I N T   h e i g h t   =   r c . b o t t o m   -   r c . t o p ; 
 
 
 
 	 U I N T   c r e a t e D e v i c e F l a g s   =   0 ; 
 
 # i f d e f   _ D E B U G 
 
 	 c r e a t e D e v i c e F l a g s   | =   D 3 D 1 1 _ C R E A T E _ D E V I C E _ D E B U G ; 
 
 # e n d i f 
 
 
 
 	 D 3 D _ D R I V E R _ T Y P E   d r i v e r T y p e s [ ]   = 
 
 	 { 
 
 	 	 D 3 D _ D R I V E R _ T Y P E _ H A R D W A R E , 
 
 	 	 D 3 D _ D R I V E R _ T Y P E _ W A R P , 
 
 	 	 D 3 D _ D R I V E R _ T Y P E _ R E F E R E N C E , 
 
 	 } ; 
 
 	 U I N T   n u m D r i v e r T y p e s   =   A R R A Y S I Z E ( d r i v e r T y p e s ) ; 
 
 
 
 	 D 3 D _ F E A T U R E _ L E V E L   f e a t u r e L e v e l s [ ]   = 
 
 	 { 
 
 	 	 D 3 D _ F E A T U R E _ L E V E L _ 1 1 _ 0 , 
 
 	 	 D 3 D _ F E A T U R E _ L E V E L _ 1 0 _ 1 , 
 
 	 	 D 3 D _ F E A T U R E _ L E V E L _ 1 0 _ 0 , 
 
 	 } ; 
 
 	 U I N T   n u m F e a t u r e L e v e l s   =   A R R A Y S I Z E ( f e a t u r e L e v e l s ) ; 
 
 
 
 	 D X G I _ S W A P _ C H A I N _ D E S C   s d ; 
 
 	 Z e r o M e m o r y ( & s d ,   s i z e o f ( s d ) ) ; 
 
 	 s d . B u f f e r C o u n t   =   1 ; 
 
 	 s d . B u f f e r D e s c . W i d t h   =   w i d t h ; 
 
 	 s d . B u f f e r D e s c . H e i g h t   =   h e i g h t ; 
 
 	 s d . B u f f e r D e s c . F o r m a t   =   D X G I _ F O R M A T _ R 8 G 8 B 8 A 8 _ U N O R M ; 
 
 	 s d . B u f f e r D e s c . R e f r e s h R a t e . N u m e r a t o r   =   6 0 ; 
 
 	 s d . B u f f e r D e s c . R e f r e s h R a t e . D e n o m i n a t o r   =   1 ; 
 
 	 s d . B u f f e r U s a g e   =   D X G I _ U S A G E _ R E N D E R _ T A R G E T _ O U T P U T ; 
 
 	 s d . O u t p u t W i n d o w   =   g _ h W n d ; 
 
 	 s d . S a m p l e D e s c . C o u n t   =   1 ; 
 
 	 s d . S a m p l e D e s c . Q u a l i t y   =   0 ; 
 
 	 s d . W i n d o w e d   =   T R U E ; 
 
 
 
 	 f o r   ( U I N T   d r i v e r T y p e I n d e x   =   0 ;   d r i v e r T y p e I n d e x   <   n u m D r i v e r T y p e s ;   d r i v e r T y p e I n d e x + + ) 
 
 	 { 
 
 	 	 g _ d r i v e r T y p e   =   d r i v e r T y p e s [ d r i v e r T y p e I n d e x ] ; 
 
 	 	 h r   =   D 3 D 1 1 C r e a t e D e v i c e A n d S w a p C h a i n ( N U L L ,   g _ d r i v e r T y p e ,   N U L L ,   c r e a t e D e v i c e F l a g s ,   f e a t u r e L e v e l s ,   n u m F e a t u r e L e v e l s , 
 
 	 	 	 D 3 D 1 1 _ S D K _ V E R S I O N ,   & s d ,   & g _ p S w a p C h a i n ,   & g _ p d 3 d D e v i c e ,   & g _ f e a t u r e L e v e l ,   & g _ p I m m e d i a t e C o n t e x t ) ; 
 
 	 	 i f   ( S U C C E E D E D ( h r ) ) 
 
 	 	 	 b r e a k ; 
 
 	 } 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 / /   C r e a t e   a   r e n d e r   t a r g e t   v i e w 
 
 	 I D 3 D 1 1 T e x t u r e 2 D *   p B a c k B u f f e r   =   N U L L ; 
 
 	 h r   =   g _ p S w a p C h a i n - > G e t B u f f e r ( 0 ,   _ _ u u i d o f ( I D 3 D 1 1 T e x t u r e 2 D ) ,   ( L P V O I D * ) & p B a c k B u f f e r ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 h r   =   g _ p d 3 d D e v i c e - > C r e a t e R e n d e r T a r g e t V i e w ( p B a c k B u f f e r ,   N U L L ,   & g _ p R e n d e r T a r g e t V i e w ) ; 
 
 	 p B a c k B u f f e r - > R e l e a s e ( ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 / /   C r e a t e   d e p t h   s t e n c i l   t e x t u r e 
 
 	 D 3 D 1 1 _ T E X T U R E 2 D _ D E S C   d e s c D e p t h ; 
 
 	 Z e r o M e m o r y ( & d e s c D e p t h ,   s i z e o f ( d e s c D e p t h ) ) ; 
 
 	 d e s c D e p t h . W i d t h   =   w i d t h ; 
 
 	 d e s c D e p t h . H e i g h t   =   h e i g h t ; 
 
 	 d e s c D e p t h . M i p L e v e l s   =   1 ; 
 
 	 d e s c D e p t h . A r r a y S i z e   =   1 ; 
 
 	 d e s c D e p t h . F o r m a t   =   D X G I _ F O R M A T _ D 2 4 _ U N O R M _ S 8 _ U I N T ; 
 
 	 d e s c D e p t h . S a m p l e D e s c . C o u n t   =   1 ; 
 
 	 d e s c D e p t h . S a m p l e D e s c . Q u a l i t y   =   0 ; 
 
 	 d e s c D e p t h . U s a g e   =   D 3 D 1 1 _ U S A G E _ D E F A U L T ; 
 
 	 d e s c D e p t h . B i n d F l a g s   =   D 3 D 1 1 _ B I N D _ D E P T H _ S T E N C I L ; 
 
 	 d e s c D e p t h . C P U A c c e s s F l a g s   =   0 ; 
 
 	 d e s c D e p t h . M i s c F l a g s   =   0 ; 
 
 	 h r   =   g _ p d 3 d D e v i c e - > C r e a t e T e x t u r e 2 D ( & d e s c D e p t h ,   N U L L ,   & g _ p D e p t h S t e n c i l ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 / /   C r e a t e   t h e   d e p t h   s t e n c i l   v i e w 
 
 	 D 3 D 1 1 _ D E P T H _ S T E N C I L _ V I E W _ D E S C   d e s c D S V ; 
 
 	 Z e r o M e m o r y ( & d e s c D S V ,   s i z e o f ( d e s c D S V ) ) ; 
 
 	 d e s c D S V . F o r m a t   =   d e s c D e p t h . F o r m a t ; 
 
 	 d e s c D S V . V i e w D i m e n s i o n   =   D 3 D 1 1 _ D S V _ D I M E N S I O N _ T E X T U R E 2 D ; 
 
 	 d e s c D S V . T e x t u r e 2 D . M i p S l i c e   =   0 ; 
 
 	 h r   =   g _ p d 3 d D e v i c e - > C r e a t e D e p t h S t e n c i l V i e w ( g _ p D e p t h S t e n c i l ,   & d e s c D S V ,   & g _ p D e p t h S t e n c i l V i e w ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 g _ p I m m e d i a t e C o n t e x t - > O M S e t R e n d e r T a r g e t s ( 1 ,   & g _ p R e n d e r T a r g e t V i e w ,   g _ p D e p t h S t e n c i l V i e w ) ; 
 
 
 
 	 / /   S e t u p   t h e   v i e w p o r t 
 
 	 D 3 D 1 1 _ V I E W P O R T   v p ; 
 
 	 v p . W i d t h   =   ( F L O A T ) w i d t h ; 
 
 	 v p . H e i g h t   =   ( F L O A T ) h e i g h t ; 
 
 	 v p . M i n D e p t h   =   0 . 0 f ; 
 
 	 v p . M a x D e p t h   =   1 . 0 f ; 
 
 	 v p . T o p L e f t X   =   0 ; 
 
 	 v p . T o p L e f t Y   =   0 ; 
 
 	 g _ p I m m e d i a t e C o n t e x t - > R S S e t V i e w p o r t s ( 1 ,   & v p ) ; 
 
 
 
 	 / /   C o m p i l e   t h e   v e r t e x   s h a d e r 
 
 	 I D 3 D B l o b *   p V S B l o b   =   N U L L ; 
 
 	 h r   =   C o m p i l e S h a d e r F r o m F i l e ( L " T u t o r i a l 0 7 . f x " ,   " V S " ,   " v s _ 4 _ 0 " ,   & p V S B l o b ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 { 
 
 	 	 M e s s a g e B o x ( N U L L , 
 
 	 	 	 L " T h e   F X   f i l e   c a n n o t   b e   c o m p i l e d .     P l e a s e   r u n   t h i s   e x e c u t a b l e   f r o m   t h e   d i r e c t o r y   t h a t   c o n t a i n s   t h e   F X   f i l e . " ,   L " E r r o r " ,   M B _ O K ) ; 
 
 	 	 r e t u r n   h r ; 
 
 	 } 
 
 
 
 	 / /   C r e a t e   t h e   v e r t e x   s h a d e r 
 
 	 h r   =   g _ p d 3 d D e v i c e - > C r e a t e V e r t e x S h a d e r ( p V S B l o b - > G e t B u f f e r P o i n t e r ( ) ,   p V S B l o b - > G e t B u f f e r S i z e ( ) ,   N U L L ,   & g _ p V e r t e x S h a d e r ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 { 
 
 	 	 p V S B l o b - > R e l e a s e ( ) ; 
 
 	 	 r e t u r n   h r ; 
 
 	 } 
 
 
 
 	 / /   D e f i n e   t h e   i n p u t   l a y o u t 
 
 	 D 3 D 1 1 _ I N P U T _ E L E M E N T _ D E S C   l a y o u t [ ]   = 
 
 	 { 
 
 	 	 {   " P O S I T I O N " ,   0 ,   D X G I _ F O R M A T _ R 3 2 G 3 2 B 3 2 _ F L O A T ,   0 ,   0 ,   D 3 D 1 1 _ I N P U T _ P E R _ V E R T E X _ D A T A ,   0   } , 
 
 	 {   " T E X C O O R D " ,   0 ,   D X G I _ F O R M A T _ R 3 2 G 3 2 _ F L O A T ,   0 ,   1 2 ,   D 3 D 1 1 _ I N P U T _ P E R _ V E R T E X _ D A T A ,   0   } , 
 
 	 } ; 
 
 	 U I N T   n u m E l e m e n t s   =   A R R A Y S I Z E ( l a y o u t ) ; 
 
 
 
 	 / /   C r e a t e   t h e   i n p u t   l a y o u t 
 
 	 h r   =   g _ p d 3 d D e v i c e - > C r e a t e I n p u t L a y o u t ( l a y o u t ,   n u m E l e m e n t s ,   p V S B l o b - > G e t B u f f e r P o i n t e r ( ) , 
 
 	 	 p V S B l o b - > G e t B u f f e r S i z e ( ) ,   & g _ p V e r t e x L a y o u t ) ; 
 
 	 p V S B l o b - > R e l e a s e ( ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 / /   S e t   t h e   i n p u t   l a y o u t 
 
 	 g _ p I m m e d i a t e C o n t e x t - > I A S e t I n p u t L a y o u t ( g _ p V e r t e x L a y o u t ) ; 
 
 
 
 	 / /   C o m p i l e   t h e   p i x e l   s h a d e r 
 
 	 I D 3 D B l o b *   p P S B l o b   =   N U L L ; 
 
 	 h r   =   C o m p i l e S h a d e r F r o m F i l e ( L " T u t o r i a l 0 7 . f x " ,   " P S " ,   " p s _ 4 _ 0 " ,   & p P S B l o b ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 { 
 
 	 	 M e s s a g e B o x ( N U L L , 
 
 	 	 	 L " T h e   F X   f i l e   c a n n o t   b e   c o m p i l e d .     P l e a s e   r u n   t h i s   e x e c u t a b l e   f r o m   t h e   d i r e c t o r y   t h a t   c o n t a i n s   t h e   F X   f i l e . " ,   L " E r r o r " ,   M B _ O K ) ; 
 
 	 	 r e t u r n   h r ; 
 
 	 } 
 
 
 
 	 / /   C r e a t e   t h e   p i x e l   s h a d e r 
 
 	 h r   =   g _ p d 3 d D e v i c e - > C r e a t e P i x e l S h a d e r ( p P S B l o b - > G e t B u f f e r P o i n t e r ( ) ,   p P S B l o b - > G e t B u f f e r S i z e ( ) ,   N U L L ,   & g _ p P i x e l S h a d e r ) ; 
 
 	 p P S B l o b - > R e l e a s e ( ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 / /   C r e a t e   v e r t e x   b u f f e r 
 
 	 S i m p l e V e r t e x   v e r t i c e s [ ]   = 
 
 	 { 
 
 	 	 {   X M F L O A T 3 ( - 1 . 0 f ,   1 . 0 f ,   - 1 . 0 f ) ,   X M F L O A T 2 ( 0 . 0 f ,   0 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( 1 . 0 f ,   1 . 0 f ,   - 1 . 0 f ) ,   X M F L O A T 2 ( 1 . 0 f ,   0 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( 1 . 0 f ,   1 . 0 f ,   1 . 0 f ) ,   X M F L O A T 2 ( 1 . 0 f ,   1 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( - 1 . 0 f ,   1 . 0 f ,   1 . 0 f ) ,   X M F L O A T 2 ( 0 . 0 f ,   1 . 0 f )   } , 
 
 
 
 	 {   X M F L O A T 3 ( - 1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ) ,   X M F L O A T 2 ( 0 . 0 f ,   0 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( 1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ) ,   X M F L O A T 2 ( 1 . 0 f ,   0 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( 1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ) ,   X M F L O A T 2 ( 1 . 0 f ,   1 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( - 1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ) ,   X M F L O A T 2 ( 0 . 0 f ,   1 . 0 f )   } , 
 
 
 
 	 {   X M F L O A T 3 ( - 1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ) ,   X M F L O A T 2 ( 0 . 0 f ,   0 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( - 1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ) ,   X M F L O A T 2 ( 1 . 0 f ,   0 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( - 1 . 0 f ,   1 . 0 f ,   - 1 . 0 f ) ,   X M F L O A T 2 ( 1 . 0 f ,   1 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( - 1 . 0 f ,   1 . 0 f ,   1 . 0 f ) ,   X M F L O A T 2 ( 0 . 0 f ,   1 . 0 f )   } , 
 
 
 
 	 {   X M F L O A T 3 ( 1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ) ,   X M F L O A T 2 ( 0 . 0 f ,   0 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( 1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ) ,   X M F L O A T 2 ( 1 . 0 f ,   0 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( 1 . 0 f ,   1 . 0 f ,   - 1 . 0 f ) ,   X M F L O A T 2 ( 1 . 0 f ,   1 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( 1 . 0 f ,   1 . 0 f ,   1 . 0 f ) ,   X M F L O A T 2 ( 0 . 0 f ,   1 . 0 f )   } , 
 
 
 
 	 {   X M F L O A T 3 ( - 1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ) ,   X M F L O A T 2 ( 0 . 0 f ,   0 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( 1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ) ,   X M F L O A T 2 ( 1 . 0 f ,   0 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( 1 . 0 f ,   1 . 0 f ,   - 1 . 0 f ) ,   X M F L O A T 2 ( 1 . 0 f ,   1 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( - 1 . 0 f ,   1 . 0 f ,   - 1 . 0 f ) ,   X M F L O A T 2 ( 0 . 0 f ,   1 . 0 f )   } , 
 
 
 
 	 {   X M F L O A T 3 ( - 1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ) ,   X M F L O A T 2 ( 0 . 0 f ,   0 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( 1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ) ,   X M F L O A T 2 ( 1 . 0 f ,   0 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( 1 . 0 f ,   1 . 0 f ,   1 . 0 f ) ,   X M F L O A T 2 ( 1 . 0 f ,   1 . 0 f )   } , 
 
 	 {   X M F L O A T 3 ( - 1 . 0 f ,   1 . 0 f ,   1 . 0 f ) ,   X M F L O A T 2 ( 0 . 0 f ,   1 . 0 f )   } , 
 
 	 } ; 
 
 
 
 	 D 3 D 1 1 _ B U F F E R _ D E S C   b d ; 
 
 	 Z e r o M e m o r y ( & b d ,   s i z e o f ( b d ) ) ; 
 
 	 b d . U s a g e   =   D 3 D 1 1 _ U S A G E _ D E F A U L T ; 
 
 	 b d . B y t e W i d t h   =   s i z e o f ( S i m p l e V e r t e x )   *   2 4 ; 
 
 	 b d . B i n d F l a g s   =   D 3 D 1 1 _ B I N D _ V E R T E X _ B U F F E R ; 
 
 	 b d . C P U A c c e s s F l a g s   =   0 ; 
 
 	 D 3 D 1 1 _ S U B R E S O U R C E _ D A T A   I n i t D a t a ; 
 
 	 Z e r o M e m o r y ( & I n i t D a t a ,   s i z e o f ( I n i t D a t a ) ) ; 
 
 	 I n i t D a t a . p S y s M e m   =   v e r t i c e s ; 
 
 	 h r   =   g _ p d 3 d D e v i c e - > C r e a t e B u f f e r ( & b d ,   & I n i t D a t a ,   & g _ p V e r t e x B u f f e r ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 / /   S e t   v e r t e x   b u f f e r 
 
 	 U I N T   s t r i d e   =   s i z e o f ( S i m p l e V e r t e x ) ; 
 
 	 U I N T   o f f s e t   =   0 ; 
 
 	 g _ p I m m e d i a t e C o n t e x t - > I A S e t V e r t e x B u f f e r s ( 0 ,   1 ,   & g _ p V e r t e x B u f f e r ,   & s t r i d e ,   & o f f s e t ) ; 
 
 
 
 	 / /   C r e a t e   i n d e x   b u f f e r 
 
 	 / /   C r e a t e   v e r t e x   b u f f e r 
 
 	 W O R D   i n d i c e s [ ]   = 
 
 	 { 
 
 	 	 3 , 1 , 0 , 
 
 	 	 2 , 1 , 3 , 
 
 
 
 	 	 6 , 4 , 5 , 
 
 	 	 7 , 4 , 6 , 
 
 
 
 	 	 1 1 , 9 , 8 , 
 
 	 	 1 0 , 9 , 1 1 , 
 
 
 
 	 	 1 4 , 1 2 , 1 3 , 
 
 	 	 1 5 , 1 2 , 1 4 , 
 
 
 
 	 	 1 9 , 1 7 , 1 6 , 
 
 	 	 1 8 , 1 7 , 1 9 , 
 
 
 
 	 	 2 2 , 2 0 , 2 1 , 
 
 	 	 2 3 , 2 0 , 2 2 
 
 	 } ; 
 
 
 
 	 b d . U s a g e   =   D 3 D 1 1 _ U S A G E _ D E F A U L T ; 
 
 	 b d . B y t e W i d t h   =   s i z e o f ( W O R D )   *   3 6 ; 
 
 	 b d . B i n d F l a g s   =   D 3 D 1 1 _ B I N D _ I N D E X _ B U F F E R ; 
 
 	 b d . C P U A c c e s s F l a g s   =   0 ; 
 
 	 I n i t D a t a . p S y s M e m   =   i n d i c e s ; 
 
 	 h r   =   g _ p d 3 d D e v i c e - > C r e a t e B u f f e r ( & b d ,   & I n i t D a t a ,   & g _ p I n d e x B u f f e r ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 / /   S e t   i n d e x   b u f f e r 
 
 	 g _ p I m m e d i a t e C o n t e x t - > I A S e t I n d e x B u f f e r ( g _ p I n d e x B u f f e r ,   D X G I _ F O R M A T _ R 1 6 _ U I N T ,   0 ) ; 
 
 
 
 	 / /   S e t   p r i m i t i v e   t o p o l o g y 
 
 	 g _ p I m m e d i a t e C o n t e x t - > I A S e t P r i m i t i v e T o p o l o g y ( D 3 D 1 1 _ P R I M I T I V E _ T O P O L O G Y _ T R I A N G L E L I S T ) ; 
 
 
 
 	 / /   C r e a t e   t h e   c o n s t a n t   b u f f e r s 
 
 	 b d . U s a g e   =   D 3 D 1 1 _ U S A G E _ D E F A U L T ; 
 
 	 b d . B y t e W i d t h   =   s i z e o f ( C B N e v e r C h a n g e s ) ; 
 
 	 b d . B i n d F l a g s   =   D 3 D 1 1 _ B I N D _ C O N S T A N T _ B U F F E R ; 
 
 	 b d . C P U A c c e s s F l a g s   =   0 ; 
 
 	 h r   =   g _ p d 3 d D e v i c e - > C r e a t e B u f f e r ( & b d ,   N U L L ,   & g _ p C B N e v e r C h a n g e s ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 b d . B y t e W i d t h   =   s i z e o f ( C B C h a n g e O n R e s i z e ) ; 
 
 	 h r   =   g _ p d 3 d D e v i c e - > C r e a t e B u f f e r ( & b d ,   N U L L ,   & g _ p C B C h a n g e O n R e s i z e ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 b d . B y t e W i d t h   =   s i z e o f ( C B C h a n g e s E v e r y F r a m e ) ; 
 
 	 h r   =   g _ p d 3 d D e v i c e - > C r e a t e B u f f e r ( & b d ,   N U L L ,   & g _ p C B C h a n g e s E v e r y F r a m e ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 / /   L o a d   t h e   T e x t u r e 
 
 	 h r   =   D 3 D X 1 1 C r e a t e S h a d e r R e s o u r c e V i e w F r o m F i l e ( g _ p d 3 d D e v i c e ,   L " s e a f l o o r . d d s " ,   N U L L ,   N U L L ,   & g _ p T e x t u r e R V ,   N U L L ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 / /   C r e a t e   t h e   s a m p l e   s t a t e 
 
 	 D 3 D 1 1 _ S A M P L E R _ D E S C   s a m p D e s c ; 
 
 	 Z e r o M e m o r y ( & s a m p D e s c ,   s i z e o f ( s a m p D e s c ) ) ; 
 
 	 s a m p D e s c . F i l t e r   =   D 3 D 1 1 _ F I L T E R _ M I N _ M A G _ M I P _ L I N E A R ; 
 
 	 s a m p D e s c . A d d r e s s U   =   D 3 D 1 1 _ T E X T U R E _ A D D R E S S _ W R A P ; 
 
 	 s a m p D e s c . A d d r e s s V   =   D 3 D 1 1 _ T E X T U R E _ A D D R E S S _ W R A P ; 
 
 	 s a m p D e s c . A d d r e s s W   =   D 3 D 1 1 _ T E X T U R E _ A D D R E S S _ W R A P ; 
 
 	 s a m p D e s c . C o m p a r i s o n F u n c   =   D 3 D 1 1 _ C O M P A R I S O N _ N E V E R ; 
 
 	 s a m p D e s c . M i n L O D   =   0 ; 
 
 	 s a m p D e s c . M a x L O D   =   D 3 D 1 1 _ F L O A T 3 2 _ M A X ; 
 
 	 h r   =   g _ p d 3 d D e v i c e - > C r e a t e S a m p l e r S t a t e ( & s a m p D e s c ,   & g _ p S a m p l e r L i n e a r ) ; 
 
 	 i f   ( F A I L E D ( h r ) ) 
 
 	 	 r e t u r n   h r ; 
 
 
 
 	 / /   I n i t i a l i z e   t h e   w o r l d   m a t r i c e s 
 
 	 g _ W o r l d   =   X M M a t r i x I d e n t i t y ( ) ; 
 
 
 
 	 / /   I n i t i a l i z e   t h e   v i e w   m a t r i x 
 
 	 X M V E C T O R   E y e   =   X M V e c t o r S e t ( 0 . 0 f ,   3 . 0 f ,   - 6 . 0 f ,   0 . 0 f ) ; 
 
 	 X M V E C T O R   A t   =   X M V e c t o r S e t ( 0 . 0 f ,   1 . 0 f ,   0 . 0 f ,   0 . 0 f ) ; 
 
 	 X M V E C T O R   U p   =   X M V e c t o r S e t ( 0 . 0 f ,   1 . 0 f ,   0 . 0 f ,   0 . 0 f ) ; 
 
 	 g _ V i e w   =   X M M a t r i x L o o k A t L H ( E y e ,   A t ,   U p ) ; 
 
 
 
 	 C B N e v e r C h a n g e s   c b N e v e r C h a n g e s ; 
 
 	 c b N e v e r C h a n g e s . m V i e w   =   X M M a t r i x T r a n s p o s e ( g _ V i e w ) ; 
 
 	 g _ p I m m e d i a t e C o n t e x t - > U p d a t e S u b r e s o u r c e ( g _ p C B N e v e r C h a n g e s ,   0 ,   N U L L ,   & c b N e v e r C h a n g e s ,   0 ,   0 ) ; 
 
 
 
 	 / /   I n i t i a l i z e   t h e   p r o j e c t i o n   m a t r i x 
 
 	 g _ P r o j e c t i o n   =   X M M a t r i x P e r s p e c t i v e F o v L H ( X M _ P I D I V 4 ,   w i d t h   /   ( F L O A T ) h e i g h t ,   0 . 0 1 f ,   1 0 0 . 0 f ) ; 
 
 
 
 	 C B C h a n g e O n R e s i z e   c b C h a n g e s O n R e s i z e ; 
 
 	 c b C h a n g e s O n R e s i z e . m P r o j e c t i o n   =   X M M a t r i x T r a n s p o s e ( g _ P r o j e c t i o n ) ; 
 
 	 g _ p I m m e d i a t e C o n t e x t - > U p d a t e S u b r e s o u r c e ( g _ p C B C h a n g e O n R e s i z e ,   0 ,   N U L L ,   & c b C h a n g e s O n R e s i z e ,   0 ,   0 ) ; 
 
 
 
 	 r e t u r n   S _ O K ; 
 
 } 
 
 
 
 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 / /   C l e a n   u p   t h e   o b j e c t s   w e ' v e   c r e a t e d 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 v o i d   C l e a n u p D e v i c e ( ) 
 
 { 
 
 	 i f   ( g _ p I m m e d i a t e C o n t e x t )   g _ p I m m e d i a t e C o n t e x t - > C l e a r S t a t e ( ) ; 
 
 
 
 	 i f   ( g _ p S a m p l e r L i n e a r )   g _ p S a m p l e r L i n e a r - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p T e x t u r e R V )   g _ p T e x t u r e R V - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p C B N e v e r C h a n g e s )   g _ p C B N e v e r C h a n g e s - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p C B C h a n g e O n R e s i z e )   g _ p C B C h a n g e O n R e s i z e - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p C B C h a n g e s E v e r y F r a m e )   g _ p C B C h a n g e s E v e r y F r a m e - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p V e r t e x B u f f e r )   g _ p V e r t e x B u f f e r - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p I n d e x B u f f e r )   g _ p I n d e x B u f f e r - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p V e r t e x L a y o u t )   g _ p V e r t e x L a y o u t - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p V e r t e x S h a d e r )   g _ p V e r t e x S h a d e r - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p P i x e l S h a d e r )   g _ p P i x e l S h a d e r - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p D e p t h S t e n c i l )   g _ p D e p t h S t e n c i l - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p D e p t h S t e n c i l V i e w )   g _ p D e p t h S t e n c i l V i e w - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p R e n d e r T a r g e t V i e w )   g _ p R e n d e r T a r g e t V i e w - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p S w a p C h a i n )   g _ p S w a p C h a i n - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p I m m e d i a t e C o n t e x t )   g _ p I m m e d i a t e C o n t e x t - > R e l e a s e ( ) ; 
 
 	 i f   ( g _ p d 3 d D e v i c e )   g _ p d 3 d D e v i c e - > R e l e a s e ( ) ; 
 
 } 
 
 
 
 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 / /   C a l l e d   e v e r y   t i m e   t h e   a p p l i c a t i o n   r e c e i v e s   a   m e s s a g e 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 L R E S U L T   C A L L B A C K   W n d P r o c ( H W N D   h W n d ,   U I N T   m e s s a g e ,   W P A R A M   w P a r a m ,   L P A R A M   l P a r a m ) 
 
 { 
 
 	 P A I N T S T R U C T   p s ; 
 
 	 H D C   h d c ; 
 
 
 
 	 s w i t c h   ( m e s s a g e ) 
 
 	 { 
 
 	 c a s e   W M _ P A I N T : 
 
 	 	 h d c   =   B e g i n P a i n t ( h W n d ,   & p s ) ; 
 
 	 	 E n d P a i n t ( h W n d ,   & p s ) ; 
 
 	 	 b r e a k ; 
 
 
 
 	 c a s e   W M _ D E S T R O Y : 
 
 	 	 P o s t Q u i t M e s s a g e ( 0 ) ; 
 
 	 	 b r e a k ; 
 
 
 
 	 d e f a u l t : 
 
 	 	 r e t u r n   D e f W i n d o w P r o c ( h W n d ,   m e s s a g e ,   w P a r a m ,   l P a r a m ) ; 
 
 	 } 
 
 
 
 	 r e t u r n   0 ; 
 
 } 
 
 
 
 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 / /   R e n d e r   a   f r a m e 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 v o i d   R e n d e r ( ) 
 
 { 
 
 	 / /   U p d a t e   o u r   t i m e 
 
 	 s t a t i c   f l o a t   t   =   0 . 0 f ; 
 
 	 i f   ( g _ d r i v e r T y p e   = =   D 3 D _ D R I V E R _ T Y P E _ R E F E R E N C E ) 
 
 	 { 
 
 	 	 t   + =   ( f l o a t ) X M _ P I   *   0 . 0 1 2 5 f ; 
 
 	 } 
 
 	 e l s e 
 
 	 { 
 
 	 	 s t a t i c   D W O R D   d w T i m e S t a r t   =   0 ; 
 
 	 	 D W O R D   d w T i m e C u r   =   G e t T i c k C o u n t ( ) ; 
 
 	 	 i f   ( d w T i m e S t a r t   = =   0 ) 
 
 	 	 	 d w T i m e S t a r t   =   d w T i m e C u r ; 
 
 	 	 t   =   ( d w T i m e C u r   -   d w T i m e S t a r t )   /   1 0 0 0 . 0 f ; 
 
 	 } 
 
 
 
 	 / /   R o t a t e   c u b e   a r o u n d   t h e   o r i g i n 
 
 	 g _ W o r l d   =   X M M a t r i x R o t a t i o n Y ( t ) ; 
 
 
 
 	 / /   M o d i f y   t h e   c o l o r 
 
 	 g _ v M e s h C o l o r . x   =   ( s i n f ( t   *   1 . 0 f )   +   1 . 0 f )   *   0 . 5 f ; 
 
 	 g _ v M e s h C o l o r . y   =   ( c o s f ( t   *   3 . 0 f )   +   1 . 0 f )   *   0 . 5 f ; 
 
 	 g _ v M e s h C o l o r . z   =   ( s i n f ( t   *   5 . 0 f )   +   1 . 0 f )   *   0 . 5 f ; 
 
 
 
 	 / / 
 
 	 / /   C l e a r   t h e   b a c k   b u f f e r 
 
 	 / / 
 
 	 f l o a t   C l e a r C o l o r [ 4 ]   =   {   0 . 0 f ,   0 . 1 2 5 f ,   0 . 3 f ,   1 . 0 f   } ;   / /   r e d ,   g r e e n ,   b l u e ,   a l p h a 
 
 	 g _ p I m m e d i a t e C o n t e x t - > C l e a r R e n d e r T a r g e t V i e w ( g _ p R e n d e r T a r g e t V i e w ,   C l e a r C o l o r ) ; 
 
 
 
 	 / / 
 
 	 / /   C l e a r   t h e   d e p t h   b u f f e r   t o   1 . 0   ( m a x   d e p t h ) 
 
 	 / / 
 
 	 g _ p I m m e d i a t e C o n t e x t - > C l e a r D e p t h S t e n c i l V i e w ( g _ p D e p t h S t e n c i l V i e w ,   D 3 D 1 1 _ C L E A R _ D E P T H ,   1 . 0 f ,   0 ) ; 
 
 
 
 	 / / 
 
 	 / /   U p d a t e   v a r i a b l e s   t h a t   c h a n g e   o n c e   p e r   f r a m e 
 
 	 / / 
 
 	 C B C h a n g e s E v e r y F r a m e   c b ; 
 
 	 c b . m W o r l d   =   X M M a t r i x T r a n s p o s e ( g _ W o r l d ) ; 
 
 	 c b . v M e s h C o l o r   =   g _ v M e s h C o l o r ; 
 
 	 g _ p I m m e d i a t e C o n t e x t - > U p d a t e S u b r e s o u r c e ( g _ p C B C h a n g e s E v e r y F r a m e ,   0 ,   N U L L ,   & c b ,   0 ,   0 ) ; 
 
 
 
 	 / / 
 
 	 / /   R e n d e r   t h e   c u b e 
 
 	 / / 
 
 	 g _ p I m m e d i a t e C o n t e x t - > V S S e t S h a d e r ( g _ p V e r t e x S h a d e r ,   N U L L ,   0 ) ; 
 
 	 g _ p I m m e d i a t e C o n t e x t - > V S S e t C o n s t a n t B u f f e r s ( 0 ,   1 ,   & g _ p C B N e v e r C h a n g e s ) ; 
 
 	 g _ p I m m e d i a t e C o n t e x t - > V S S e t C o n s t a n t B u f f e r s ( 1 ,   1 ,   & g _ p C B C h a n g e O n R e s i z e ) ; 
 
 	 g _ p I m m e d i a t e C o n t e x t - > V S S e t C o n s t a n t B u f f e r s ( 2 ,   1 ,   & g _ p C B C h a n g e s E v e r y F r a m e ) ; 
 
 	 g _ p I m m e d i a t e C o n t e x t - > P S S e t S h a d e r ( g _ p P i x e l S h a d e r ,   N U L L ,   0 ) ; 
 
 	 g _ p I m m e d i a t e C o n t e x t - > P S S e t C o n s t a n t B u f f e r s ( 2 ,   1 ,   & g _ p C B C h a n g e s E v e r y F r a m e ) ; 
 
 	 g _ p I m m e d i a t e C o n t e x t - > P S S e t S h a d e r R e s o u r c e s ( 0 ,   1 ,   & g _ p T e x t u r e R V ) ; 
 
 	 g _ p I m m e d i a t e C o n t e x t - > P S S e t S a m p l e r s ( 0 ,   1 ,   & g _ p S a m p l e r L i n e a r ) ; 
 
 	 g _ p I m m e d i a t e C o n t e x t - > D r a w I n d e x e d ( 3 6 ,   0 ,   0 ) ; 
 
 
 
 	 / / 
 
 	 / /   P r e s e n t   o u r   b a c k   b u f f e r   t o   o u r   f r o n t   b u f f e r 
 
 	 / / 
 
 	 g _ p S w a p C h a i n - > P r e s e n t ( 0 ,   0 ) ; 
 
 } 
 
 