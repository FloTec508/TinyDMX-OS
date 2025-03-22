TEMPLATE = subdirs

SUBDIRS += fixtures
SUBDIRS += gobos
SUBDIRS += inputprofiles
SUBDIRS += miditemplates
SUBDIRS += modifierstemplates
SUBDIRS += rgbscripts
SUBDIRS += samples
SUBDIRS += style
qmlui {
  SUBDIRS += colorfilters
  SUBDIRS += meshes
}

