pkgname=dwm
pkgver=6.0
pkgrel=4
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
options=(zipman)
depends=('libx11' 'libxinerama' 'pango')
install=dwm.install
source=(http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
	dwm.desktop
	config.h
  	gaplessgrid.c)

_patches=(01-6.0-pango.diff
	  02-6.0-maximize.diff
	  03-6.0-swapfocus.diff
	  04-6.0-pertag.diff)

source=(${source[@]} ${_patches[@]})

build() {
  cd $srcdir/$pkgname-$pkgver


  for p in "${_patches[@]}"; do
    echo "=> $p"
    patch -Np1 < ../$p || return 1
  done

  cp $srcdir/config.h config.h
  cp $srcdir/gaplessgrid.c gaplessgrid.c

  sed -i 's/CPPFLAGS =/CPPFLAGS +=/g' config.mk
  sed -i 's/^CFLAGS = -g/#CFLAGS += -g/g' config.mk
  sed -i 's/^#CFLAGS = -std/CFLAGS += -std/g' config.mk
  sed -i 's/^LDFLAGS = -g/#LDFLAGS += -g/g' config.mk
  sed -i 's/^#LDFLAGS = -s/LDFLAGS += -s/g' config.mk
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
  cd $srcdir/$pkgname-$pkgver
  make PREFIX=/usr DESTDIR=$pkgdir install
  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
  install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
  install -m644 -D $srcdir/dwm.desktop $pkgdir/usr/share/xsessions/dwm.desktop
}
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '939f403a71b6e85261d09fc3412269ee'
         '39fbfaa423ebc40b1ecb92eecf4ea638'
         '4ba509b3b93f7b1418dc703c70de536f'
         '983aa266382db7e0e05e93617f33024e'
         '7a598c9fbb18bac61faab67a3fe42a86'
         'd4c301f72ea9d07b443f6cc44a6de551'
         '7f7580e8b77e6f77f27a7bb009173757')
