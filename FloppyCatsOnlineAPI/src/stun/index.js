import Router from 'koa-router'

const router = new Router()

router.get('/', (ctx, next) => {
    ctx.body = {
        _ip:
            ctx.request.headers['x-forwarded-for'] ||
            ctx.request.socket.remoteAddress,
        _port:
            ctx.request.headers['x-forwarded-port'] ||
            ctx.request.socket?.remotePort,
    }
    next()
})

export default router.routes()
