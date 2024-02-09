```js
{
    const html2canvasScript = document.createElement('script');
    html2canvasScript.src = "https://html2canvas.hertzen.com/dist/html2canvas.min.js";
    html2canvasScript.addEventListener('load', () => {
        const keyboardElement = document.getElementById('keyboard-bg');
        keyboardElement.style.border = "none";
        keyboardElement.style.borderRadius = 0;
            
        document.body.style.zoom = "250%";
        
        html2canvas(keyboardElement)
            .then((canvas) => {
                document.body.appendChild(canvas)
            })
            .then(() => {
                document.body.style.zoom = "100%";
            });
    });
    document.head.appendChild(html2canvasScript);
}
```