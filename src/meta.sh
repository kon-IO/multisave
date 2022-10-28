for i in *.h; do
	moc $i -o "$i".meta
done
