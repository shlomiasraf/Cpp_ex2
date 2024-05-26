קודם כל אסביר על מימוש האופרטורים שנוספו למטלה:

**הראשון: +** פשוט מחבר את ערכי שתי המטריצות מאותו סדר גודל ע״י ריצה על איבריהם למטריצה חדשה וטוען אותה.

אם המטריצות לא מאותו סדר גודל יחזיר שגיאה.

**הבא +=** מוסיף את ערכי המטריצה השניה לראשונה ע״י ריצה על איבריהם ומחזיר אותה.

אם המטריצות לא מאותו סדר גודל יחזיר שגיאה.

**הבא + אונרי** - רצה על איברי המטריצה הופכת את כל הערכים השליליים במטריצה לחיובים (עושה להם ערך מוחלט),
לחיובים לא עושה דבר.

**עבור - -= - אונרי אותו דבר בדיוק רק עם חיסור במקום חיבור, לגבי - אונרי פשוט הופך את הערכים החיוביים לשליליים ולשליליים לא עושה דבר.** 

**אופרטור > גדול** - בהתאם להוראות המטלה בודק קודם אם מטריצה אחת מוכלת ממש בשניה ע״י ריצה על איברי המטריצה הקטנה מביניהם, אם כן ההיא שהיא מוכלת בה ממש גדולה ממנה.

אם לא והם לא שוות, בודקת למי יש יותר צלעות ולפי זה יודעת מי יותר גדולה.

אם מספר הצלעות שווה, בודקת מי בעלת סדר גודל יותר גבוה ולפי זה יודעת מי יותר גדולה. 


**אופרטור == שיויוון** - בודקת אם המטריצות בעלות אותו סדר גודל, ובעלות אותו משקלים של הצלעות ע״י ריצה על איבריהם.

אם כן מחזירה שהם שוות.


**>= גדול או שווה** - בודקת אם הגרף הראשון גדול מהגרף השני לפי האופרטור שמימשתי **או**  אם הם שווים לפי האופרטור שמימשתי.

**!= שונה** - בודקת אם הגרף הראשון **לא שווה** לגרף השני לפי האופרטור שיויוון שמימשתי.

**< קטן** - בודקת אם הגרף הראשון **לא** גדול מהגרף השני לפי האופרטור שמימשתי **וגם**  אם הם **לא** שווים לפי האופרטור שמימשתי.

**< קטן או שווה** - בודקת אם הגרף הראשון קטן מהגרף השני לפי האופרטור שמימשתי **או**  אם הם שווים לפי האופרטור שמימשתי.

**אופרטור ++ הגדלה ב-1** - מוסיף לכל ערכי המטריצה, המשקלים של הצלעות 1 ע״י ריצה על איבריה.

**אופרטור -- הקטנה ב-1** - מוריד לכל ערכי המטריצה, המשקלים של הצלעות 1 ע״י ריצה על איבריה.

**אופרטור** *= **הכפלה בסקלאר** - מכפיל את כל ערכי המטריצה ע״י ריצה על איבריה, המשקלים של הצלעות בסקלאר ומחזיר אותה.

**אופרטור /= חילוק בסקלאר** - מחלק את כל ערכי המטריצה ע״י ריצה על איבריה, המשקלים של הצלעות בסקלאר ומחזיר אותה.

**אופרטור * הכפלת גרפים** - מכפיל את ערכי המטריצות המייצגות של הגרפים ע״י ריצה על איבריהם, לפי ההגדרה של הכפלת מטריצות שורות כפול עמודות.

ומכניס את תוצאות ההכפלה למטריצה חדשה וטוען אותה. רק אם המטריצות שהוכפלו מאותו סדר גודל,
אם לא יחזיר מראש שגיאה.

**אופרטור >> הדפסה של הגרף** - מדפיס את המטריצה המייצגת של הגרף ע״י ריצה על איבריה כאשר כל שורה [צלע 3, צלע 2, צלע 1] במבנה הזה ויש פסיקים בין השורות לדוגמה:
כאשר המטריצה היא 3X3: [0, 1, 0], [1, 0, 1], [0, 1, 0]

בהתאם לאופרטורים האלה אותם מימשתי בניתי **20 טסטים במחלקה tests** שעובדים. 

**ובניתי makefile** שבאמצעות הפקודה make runDemo נריץ את ה-demo
ובאמצעות make runTest נריץ את הטסטים.

זהו (:







