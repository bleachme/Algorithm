for (var i = this.rowCount * this.colCount - 1; i >= 0 ; i--){
  var iX = parseInt(i / this.colCount);
  var iY = i % this.colCount;

  var randNumber = this.rangeRandom(0, i + 1);

  var randX = parseInt(randNumber / this.colCount);
  var randY = randNumber % this.colCount;

 //交换两个位置
  var temp = tmpMineMap[iX][iY];
  tmpMineMap[iX][iY] = tmpMineMap[randX][randY];
  tmpMineMap[randX][randY] = temp;
}

 