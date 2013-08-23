Stackato App for Stackato documentation
=======================================

1. Make sure that $STACKATO_DOCS_PASSWD is set to the password
   of the production docs server. For example ``export STACKATO_DOCS_PASSWD="rubberflubber" ``,
   or edit your ~/.bashrc and put that export command in there, then ``source ~/.bashrc``.
2. ** check out the release branch in the VCAP repo (for NEWS.txt) **
3. Run `make push-live` from the main `docs` directory.

!! This will push to the production server, docs.stackato.com !!
