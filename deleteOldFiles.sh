#!/bin/bash
ALLHTMLFILES=$(find docs -name \*.html)
for FILE in $ALLHTMLFILES; do
   FIRSTFIX=${FILE/.html/.md}
   MDFILE=${FIRSTFIX/docs/.}
   PDFFILE=${FILE/.html/.pdf}
   if ! [ -f "$MDFILE" ]; then
      rm $FILE; echo "DELETING: $FILE"
      rm $PDFFILE; echo "DELETING: $PDFFILE"
   fi
done

