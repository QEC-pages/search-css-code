
## goal

search for good CSS codes and give a table for parameters
[n,k,(d_x,d_z)]. The distance is estimated by Covering Set algorithm,
(sometimes refered as random window algorithm). It is fast, but only
gives an upper bound on the distance, which approches to the actual
distance when repeated long enough. The convergence speed decay
exponentially with code size.

## How to use
a summary is given in [css.log](css.log) in increasing order of n, k. each entry is the maximum (d_x, d_z) found for that [n, k]. 0 means nothing found for that entry.



## TODO
- [ ] save corresponding codes for each entry in the table.












## Acknowledgement
This table is inspired by [code table](http://www.codetables.de/)
