TEMPLATE = template.html
TEXTEMPLATE = template.tex
CURR:=$(shell pwd)
MDFILES := $(shell find . -name \*.md | grep -v -e "/exams/")
HTMLFILES := $(MDFILES:./%.md=docs/%.html)
# ASSIGNMENTS := $(filter ./assignments/%.md,$(MDFILES))
PDFS := $(MDFILES:./%.md=docs/%.pdf)
# TEXS := $(ASSIGNMENTS:./%.md=docs/%.tex)
IMGFILES := $(shell find images -name \*.png)
IMGFILES := $(IMGFILES:%=docs/%)

$(HTMLFILES): docs/%.html: %.md $(TEMPLATE)
	mkdir -p $(@D)
	pandoc -o $@ --template=$(TEMPLATE) --mathjax --smart --filter ./makeHtml.hs $<

$(PDFS): docs/%.pdf: %.md $(TEXTEMPLATE)
	mkdir -p $(@D)
	cd $(@D); pandoc -o $(CURR)/$@ --template=$(CURR)/$(TEXTEMPLATE) -t latex --listings  --filter $(CURR)/makeTex.hs --extract-media=$(CURR)/images --resource-path=.:$(CURR)/images $(CURR)/$<; cd $(CURR)

$(IMGFILES): docs/images/%.png: images/%.png
	mkdir -p $(@D)
	cp $< $@

email:
	open "mailto:`cat students.txt`"

site: $(HTMLFILES) $(PDFS) $(IMGFILES)

pdf: $(PDFS) $(IMGFILES)

all: site
