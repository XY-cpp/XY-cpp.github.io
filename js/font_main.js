fontAns = "221212211121122112221111122211122212111222112222211212222212112221212111221121122222112221212221222211211122112212121122212121211112222212121212212211111211111221121222211122212212121112212122121221222111222221221222222212212222112122111122212211211111122112121222112211122212111122212122222212222221111111212221221221212212112222212221222111122222121212211111221122211212221212111121122212211222112122221212222122112221122221112222122121212121211222121212221112111112121122221111211111111211121112111212211212212221112121122211122212122221122112112212212221112121121222112111221211222211210000000000";
var store = window.localStorage;
if (store.fontIn == undefined)
    store.fontIn = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
function check(d) {
    for (var i = d * 20; i < (d + 1) * 20; i++)
        if (store.fontIn[i] != fontAns[i])
            return false;
    return true;
}
function fill(d) {
    var s = document.getElementsByClassName("btn-grp");
    for (var i = 0; i < s.length; i++) {
        var t = document.getElementsByName("d" + d + "_t" + (i + 1));
        for (var j = 0; j < t.length; j++) {
            if (t[j].value == store.fontIn[(d - 1) * 20 + i])
                t[j].checked = true;
        }
    }
}
const replaceStr = (str, index, char) => {
    return str.substring(0, index) + char + str.substring(index + 1);
}
function submit(d) {
    var s = document.getElementsByClassName("btn-grp");
    for (var i = 0; i < s.length; i++) {
        var t = document.getElementsByName("d" + d + "_t" + (i + 1));
        for (var j = 0; j < t.length; j++) {
            if (t[j].checked) {
                store.fontIn = replaceStr(store.fontIn, (d - 1) * 20 + i, t[j].value);
            }
        }
    }
    window.location.href = "day" + d + "_ans.html";
}
function remove(d)
{
    store.fontIn = store.fontIn.substring(0, (d - 1) * 20) + "000000000000000000000000000000" + store.fontIn.substring(d * 20);
    window.location.href = "day" + d + ".html";

}
function judge(d) {
    var tmp = document.getElementsByClassName("border");
    for(var i = 1;i <= tmp.length;i++)
    {
        var s = document.getElementById(i);
        if(store.fontIn[(d-1)*20+i-1] != fontAns[(d-1)*20+i-1] )
            s.className='WA';
    }
}