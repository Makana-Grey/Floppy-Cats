import Router from 'koa-router'

const router = new Router()

router.get('/', (ctx, next) => {
    ctx.body = ctx.request.ip
    next()
})

export default router.routes()